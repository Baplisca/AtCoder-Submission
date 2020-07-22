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
    ll n,C; cin >> n >> C;
    vvl d(C,vl(C));
    rep(i,C)rep(j,C)cin>>d[i][j];
    vvl c(n,vl(n));
    rep(i,n)rep(j,n)cin>>c[i][j];
    ll res = L_INF;

    vvl cost(3,vl(C)); //cost[i][j]: あまりの集合iをjに塗り替えるコスト
    rep(i,C){
        rep(j,n){
            rep(k,n){
                cost[(j+k+2)%3][i] += d[c[j][k] - 1][i];
            }
        }
    }
    rep(i,C){ //あまり0でぬる色
        rep(j,C){ //1
            rep(k,C){ //2
                if(i == j || j == k || k == i)continue;
                ll ans = 0;
                rep(ii,3){
                    if(ii==0)ans += cost[ii][i];
                    else if(ii == 1) ans += cost[ii][j];
                    else ans += cost[ii][k];
                }
                res = min(ans,res);
            }
        }
    }
    out(res);
}