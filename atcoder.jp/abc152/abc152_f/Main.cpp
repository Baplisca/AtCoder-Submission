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

typedef long long ll;
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
//以降 cin の入力元が 'input.txt' になる
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

signed main()
{   
    gearup;
    int n; cin >> n;
    vvl g(n);
    map<pair<int,int>,int> id;
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--;b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        if(a > b)swap(a,b);
        id[{a,b}] = i;
    }
    int m; cin >> m;
    vl path(m,0);
    rep(i,m){
        int u,v; cin >> u >> v;
        u--;v--;
        queue<pair<int,int> > que;
        vl prev(n,-2);
        vl dists(n,-1);
        que.push({u, 0});
        dists[u] = 0;
        while(!que.empty()){
            int node = que.front().first;
            int dist = que.front().second;
            que.pop();
            for(auto nv:g[node]){
                if(dists[nv] != -1)continue;
                dists[nv] = dist + 1;
                prev[nv] = node;
                que.push({nv, dist+1});
            }
        }
        while(1){
                int a = v; //初めの位置
                int b = prev[v]; //次の位置
                if(b == -2)break;
                int tmp1 = min(a,b);
                int tmp2 = max(a,b);
                path[i] |= (1LL << id[{tmp1,tmp2}]);
                v = prev[v];
        }
        //out(path[i]);
    }
    ll res = 0;
    //制約を全探索する
    for(ll i=0;i < (1LL<<m);i++){
        ll now = 0;
        rep(j,m)if(i & (1LL<<j))now |= path[j];
        ll tmp = __builtin_popcountl(now); //黒が一個以上

        int white = __builtin_popcountll(now);  // 白くなるべき辺の数
        ll num = 1LL << (n - 1 - white);
        if(__builtin_popcountl(i) % 2 == 0)res += num;
        else res -= num;
        //out(res);
    }
    out(res);
}