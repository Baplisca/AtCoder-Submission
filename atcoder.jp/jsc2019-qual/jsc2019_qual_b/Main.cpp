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

struct mint {
    long long x;
    mint(long long x=0):x((x%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
    	return *this;
    }
    mint& operator*=(const mint a) {
    	(x *= a.x) %= MOD;
    	return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
    	if (t&1) a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const {
        return pow(MOD-2);
    }
    mint& operator/=(const mint a) {
    	return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};

struct BIT {
    private:
    vector<int> bit;
    int N;

    public:
    BIT(int size) {
      N = size;
      bit.resize(N + 1);
    }

    // aがインデックスの場所,wはaの値
    void add(int a, int w) {
      for (int x = a; x <= N; x += x & -x) bit[x] += w;
    }

    // 1~Nまでの和を求める
    int sum(int a) {
      int ret = 0;
      for (int x = a; x > 0; x -= x & -x) ret += bit[x];
      return ret;
    }
};

signed main()
{   
    gearup;
    ll n,k; cin >> n >> k;
    vl a(n);
    rep(i,n)cin>>a[i];
    mint res = 0;
    mint inv2 = 2;
    inv2 = inv2.inv(); // 1/2 の逆元 2^(-1) = 2^(MOD-2)
    
    BIT bit(2010);
    rep(i,n)bit.add(a[i],1);
    BIT bit1(2010);
    //数列a(n)を見て自分より左の数字が大きい時カウント
    rep(i,n){
        ll left = 0;
        left += i - bit1.sum(a[i]);
        bit1.add(a[i],1);
    
        ll t = n - bit.sum(a[i]);
        //初項: left
        //末項: left+total*(k-1)
        //全体 = (2left+t(k-1))*k/2;
        ll tmp = (2*left+t*(k-1)) % MOD;
        res += inv2*tmp*k; 
    }
    out(res.x);
}
