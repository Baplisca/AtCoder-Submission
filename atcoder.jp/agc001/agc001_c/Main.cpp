#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<bool> > vvb;
typedef vector<vector<double> > vvd;
typedef vector<vector<string> > vvs;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

ll ans;
int n,k;
vvl G;
vb visited;
void dfs(int node,int dist,ll &ans){
    if(dist > k/2)ans++;
    visited[node] = true;
    for(auto nv:G[node]){
        if(visited[nv] == false)dfs(nv,dist+1,ans);
    }
}
signed main()
{   
    gearup;
    cin >> n >> k;
    G.resize(n);
    visited.resize(n);
    vpii edge;
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--;b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        edge.emplace_back(a,b);
    }
    ll res = L_INF;
    if(k % 2 == 0){
        rep(i,n){
            ans = 0;
            rep(i,n)visited[i]=false;
            dfs(i,0,ans);
            res = min(res,ans);
        }
    }
    else{
        k--;
        rep(i,n-1){
            int a = edge[i].first;
            int b = edge[i].second;
            rep(i,n)visited[i] = false;
            visited[a] = true;
            visited[b] = true;
            ans = 0;
            dfs(a,0,ans);
            dfs(b,0,ans);
            res = min(res,ans);
        }
    }
    out(res);
}
