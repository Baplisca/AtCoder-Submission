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

signed main()
{   
  gearup;
  ll h,w; cin >> h >> w;
  vvl a(h,vl(w));
  rep(i,h)rep(j,w)cin>>a[i][j];
  vpii s;
  vector<pair<pair<int,int>,pair<int,int> > > res;
  rep(i,h){
      rep(j,w){
          int k = j;
          if(i & 1)k = w - 1 - j;
          s.emplace_back(i,k);
      }
  }
  rep(i,h*w-1){
      int x = s[i].first;
      int y = s[i].second;
      if(a[x][y] & 1){
          int nx = s[i+1].first;
          int ny = s[i+1].second;
          a[nx][ny]++;
          res.emplace_back(s[i],s[i+1]);
      }
  }
  out(res.size());
  rep(i,res.size()){
      cout << res[i].first.first+1 << " " << res[i].first.second+1
       << " " << res[i].second.first+1<< " " << res[i].second.second+1 << endl;
  }
}
