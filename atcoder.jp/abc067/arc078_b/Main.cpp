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

typedef long long  ll;
typedef long double ld;
typedef unsigned long long ull;
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

signed main()
{   
    gearup;
    ll n; cin >> n;
    vvl edge(n);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    queue<int> que;
    vl dist(n,L_INF);
    vl prev(n);
    dist[0] = 0;
    que.push(0);
    while(!que.empty()){
        int node = que.front();
        que.pop();
        for(auto nv:edge[node]){
            if(dist[nv] == L_INF){
                dist[nv] = dist[node]+1;
                prev[nv] = node;
                que.push(nv);
            }
        }
    }
    ll half_dist = (dist[n-1]-1)/2 + 1;
    ll from_n = n-1;
    ll to_n;
    //nから1までの経路半分探索
    rep(i,half_dist){
        to_n = prev[from_n];
        if(i != half_dist-1)from_n = to_n;
    }
    ll to_1 = from_n;

    //out(to_1);
    //out(to_n);

    //ノード1から幅優先で,to_1になったら探索中止
    ll res1 = 0;
    vl dist1(n,L_INF);
    dist1[0] = 0;
    queue<int> que1;
    que1.push(0);
    while(!que1.empty()){
        int node = que1.front();
        que1.pop();
        for(auto nv:edge[node]){
            if(dist1[nv] == L_INF && nv != to_1){
                res1++;
                dist1[nv] = dist1[node]+1;
                que1.push(nv);
            }
        }
    }
    //out(res1);

    //ノードnから幅優先で,to_nになったら探索中止
    ll resn = 0;
    dist1[n-1] = 0;
    que1.push(n-1);
    while(!que1.empty()){
        int node = que1.front();
        que1.pop();
        for(auto nv:edge[node]){
            if(dist1[nv] == L_INF && nv != to_n){
                resn++;
                dist1[nv] = dist1[node]+1;
                que1.push(nv);
            }
        }
    }
    //out(resn);
    if(res1 > resn)out("Fennec");
    else out("Snuke");
}
