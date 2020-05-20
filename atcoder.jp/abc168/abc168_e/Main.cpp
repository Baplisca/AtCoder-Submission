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

using P = pair<int,int>;
signed main()
{   
  gearup;
  int n; cin >> n;
  ll z = 0;
  map<pair<ll,ll>,P> mp;
  rep(i,n){
      ll a,b; cin >> a >> b;
      if(a == 0 && b == 0){
          z++;
          continue;
      }
      ll gcd = __gcd(a,b);
      a/=gcd;
      b/=gcd;
      if(b < 0){ //第一事象か第二事象に移す
          b*=-1;
          a*=-1;
      }
      bool phase2 = (a<=0); //第二事象か
      if(phase2){ //第二から第一事象に90回転
        swap(a,b);
        b=-b;
      }
      if(phase2)mp[{a,b}].first++;
      else mp[{a,b}].second++;
  }

  mint res = 1;
  for(auto m:mp){
      ll s = m.second.first;
      ll p = m.second.second;
      mint tmp = -1; //sとp両方から選ばない
      tmp += mint(2).pow(s);
      tmp += mint(2).pow(p);
      res *= tmp;
  }
  res = res + z;
  res -= 1;
  out(res.x);
}
