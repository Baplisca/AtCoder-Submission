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

int v[3010][3010];
ll dp[3010][3010][5];
signed main()
{
    gearup;
    ll R,C,K; cin >> R >> C >> K;
    rep(i,K){
        int r,c,k; cin >> r >> c >> k;
        v[--r][--c] = k;
    }
    rep(i,R+1){
        rep(j,C+1){
            rep(k,4){
                //上
                chmax(dp[i+1][j][0], dp[i][j][k]);
                if(j-1 >= 0)chmax(dp[i+1][j][1], dp[i][j][k] + v[i][j-1]);

                //右
                chmax(dp[i][j+1][k], dp[i][j][k]);
                if(i-1 >= 0)chmax(dp[i][j+1][k+1], dp[i][j][k] + v[i-1][j]);
            }
        }
    }
    ll res = 0;
    rep(i,3)res = max(res, dp[R][C][i+1]);
    out(res);
}   