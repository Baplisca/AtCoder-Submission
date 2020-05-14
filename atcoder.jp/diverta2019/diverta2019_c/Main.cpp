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
//ll MOD = 1000000007;
ll MOD = 998244353;
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
  ll n; cin >> n;
  //先頭と末尾に注目する
  //B〇〇は,〇〇Aの後ろについた方がいい
  //B〇〇Aは上の足りない方につける
  deque<string> a,b,c,d;
  ll ans = 0;
  rep(i,n){
      string t; cin >> t;
      int m = t.size();
      if(t[0] == 'B' && t.back() == 'A')d.emplace_back(t);
      else if(t[0] == 'B')b.emplace_back(t);
      else if(t.back() == 'A')a.emplace_back(t);
      else c.emplace_back(t);
      rep(j,m-1)if(t[j] == 'A' && t[j+1] == 'B')ans++;
  } 
  ll as = a.size();
  ll bs = b.size();
  ll ds = d.size();
  if(as+bs == 0)ans+=max(0LL,ds-1);
  else ans+= ds+min(as,bs);
  out(ans);
}
