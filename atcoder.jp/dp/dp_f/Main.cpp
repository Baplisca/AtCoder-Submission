#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(v) (v).begin(), (v).end()
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
    string s,t;cin>>s>>t;
    vvl dp(3010,vl(3010,0));
    rep(i,s.size()){
        rep(j,t.size()){
            if(s[i]==t[j])chmax(dp[i+1][j+1],dp[i][j]+1);
            chmax(dp[i+1][j+1],dp[i][j+1]);
            chmax(dp[i+1][j+1],dp[i+1][j]);
        }
    }
    //out(dp[s.size()][t.size()]);
    
    // 復元
    string res = "";
    int i = (int)s.size(), j = (int)t.size();
    while (i > 0 && j > 0)
    {
        // (i-1, j) -> (i, j) と更新されていた場合
        if (dp[i][j] == dp[i-1][j]) {
            --i; // DP の遷移を遡る
        }

        // (i, j-1) -> (i, j) と更新されていた場合
        else if (dp[i][j] == dp[i][j-1]) {
            --j; // DP の遷移を遡る
        }

        // (i-1, j-1) -> (i, j) と更新されていた場合
        else {
            res = s[i-1] + res; // このとき s[i-1] == t[j-1] なので、t[j-1] + res でも OK
            --i, --j; // DP の遷移を遡る
        }
    }
    cout << res << endl;
}
