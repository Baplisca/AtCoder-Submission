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
    ll n,T; cin >> n >> T;
    vl t(n),v(n);
    rep(i,n)cin>>t[i]>>v[i];
    vvl dp(T+10,vl(n+10)); //dp[i][j] := [1, j]品目まで食べるかを選んで、iの時間がかかったときのおいしさの最大値
    vvl dp2(T+10,vl(n+10)); //dp2[i][j] := [j,n]品目

    dp[0][0] = 0;
    rep(i,T){
        rep(j,n){
            if(t[j] <= i)chmax(dp[i][j+1], dp[i-t[j]][j] + v[j]); //選ぶ
            chmax(dp[i][j+1],dp[i][j]); //選ばない
        }
    }

    dp2[0][n+1] = 0;
	rep(i,T){
		for(int j = n; j >= 1; j--){
			chmax(dp2[i][j],dp2[i][j+1]);
			if (i - t[j - 1] >= 0)chmax(dp2[i][j], dp2[i-t[j-1]][j+1] + v[j-1]);
		}
	}
    ll res = -L_INF;
    rep(i,T){
        rep(j,n){
            chmax(res,dp[i][j] + dp2[T-1-i][j+2] + v[j]);
        }
    }
    out(res);
}