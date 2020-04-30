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

map<ll,ll> factorize(ll n){
    map<ll,ll> ret;
    ll x = n;
    for(ll i = 2; i*i<=n;i++){
        while(x % i == 0){
            ret[i]++;
            x /= i;
        }
    }
    if(x != 1)ret[x]++;
    return ret;
}

// a^b mod を計算する
ll mod_pow(ll a, ll b, ll p) {
    if (b == 0) return 1;
    if (b & 1) return (a * mod_pow(a, b - 1, p)) % p;
    ll t = mod_pow(a, b / 2, p);
    return (t * t) % p;
}

ll mod_inv(ll a, ll p) { return mod_pow(a, p - 2, p); }

signed main()
{   
    gearup;
    ll n; cin >> n;
    vl a(n);
    rep(i,n)cin>>a[i];
    map<ll,ll> lcm;
    rep(i,n){
        map<ll,ll> res = factorize(a[i]);
        for(auto re:res){
            if(lcm[re.first] < re.second) lcm[re.first] = re.second;
        }
    }
    ll lcm_mod = 1;
    for(auto lc:lcm){
        lcm_mod = lcm_mod * mod_pow(lc.first,lc.second,MOD) % MOD;
    }

    vl l(n+1,1),r(n+1,1);
    for (int i = 0; i < n; i++)l[i + 1] = l[i] * a[i] % MOD;
    for (int i = n; i > 0; i--)r[i - 1] = r[i] * a[i - 1] % MOD;

    ll nume = 0; //分子
    for (int i = 0; i < n; i++) nume = (nume + l[i] * r[i + 1] % MOD) % MOD;

    ll deno = 1; //分母
    for (int i = 0; i < n; i++) deno = deno * a[i] % MOD;

    out(lcm_mod * nume % MOD * mod_inv(deno,MOD) % MOD);
}
