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

typedef long long int ll;
typedef long double ld;
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

signed main()
{   
    gearup;
    ll n,m;
    string s; cin >> n >> m >> s;
    reverse(all(s));
    vl dp(n+1,L_INF);
    dp[0] = 0;
    rep(i,n){
        ll sub = (n+1)-i;
        bool check = false;
        for(int j=min(m,sub);j>0;j--){
            if(i+j <= n){
                if(s[i+j] != '1'){
                    chmin(dp[i+j],dp[i]+1);
                    check = true;
                    break;
                }
            }
        }
        if(check == false){
            out(-1);
            return 0;
        }
    }
    if(dp[n] == L_INF){
        out(-1);
        return 0;
    }
    vl res;
    //dpの後ろから歩数をとる
    ll pre = dp[n];
    ll dist = n;
    for(int i=n-1;i>=0;i--){
        if(pre - dp[i] == 1){
            pre = dp[i];
            res.push_back(dist - i);
            dist = i;
        }
    }
    rep(i,res.size())out(res[i]);
}