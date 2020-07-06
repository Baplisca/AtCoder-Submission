#include <bits/stdc++.h>
using namespace std;

#define int long long
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
    int n,W; cin >> n >> W;

    int init_w,init_v;
    vvl va(4);
    cin >> init_w >> init_v;
    va[0].push_back(init_v);
    rep1(i,n){
        int w,v; cin >> w >> v;
        va[w-init_w].push_back(v);
    }
    rep(i,4)sort(rall(va[i]));

    vl sva1(va[0].size()+1);
    rep(i,va[0].size())sva1[i+1] = sva1[i] + va[0][i];
    vl sva2(va[1].size()+1);
    rep(i,va[1].size())sva2[i+1] = sva2[i] + va[1][i];
    vl sva3(va[2].size()+1);
    rep(i,va[2].size())sva3[i+1] = sva3[i] + va[2][i];
    vl sva4(va[3].size()+1);
    rep(i,va[3].size())sva4[i+1] = sva4[i] + va[3][i];

    ll res = 0;
    rep(i,va[0].size() + 1){
        rep(j,va[1].size() + 1){
            rep(k,va[2].size() + 1){
                rep(v,va[3].size() + 1){
                    ll t_wei = init_w * i + (init_w + 1) * j + (init_w + 2) * k + 
                    (init_w + 3) * v;
                    if(t_wei <= W)res = max(res,sva1[i]+sva2[j]+sva3[k]+sva4[v]);
                }
            }
        }
    }
    out(res);

}