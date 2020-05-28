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
  ll n,k; cin >> n >> k;
  vl t(n),d(n); //tがネタ種類, dが美味しさ
  vpii p;
  rep(i,n){
    cin>>t[i]>>d[i];
    p.push_back({d[i],t[i]});
  }
  sort(rall(p)); //昇順ソート
  ll res = 0;
  map<int,int> mp;
  vector<int> b(n+1); //最大値をいれる
  priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > que;//降順ソート
  rep(i,k){
    res += p[i].first;
    mp[p[i].second]++;
    b[p[i].second] = max(p[i].first,b[p[i].second]);
  }
  rep(i,k){ //同じ種類が2つ以上のもので最大ではない値をqueにいれる
    if(mp[p[i].second] >= 2) if(b[p[i].second] != p[i].first)que.push({p[i].first,p[i].second});
  }
  ll type = mp.size();
  res += type*type;
  ll ans = res;
  
  int idx = k;
  while(1){ //終了条件queが空か,n種類になったか,nまで選んだか
    if(que.empty() || idx >= n)break;
    int num = que.top().first;
    que.pop();
    bool is_res = false;
    int num1;
    while(idx < n){
      num1 = p[idx].first;
      int type1 = p[idx++].second;
      if(mp[type1] == 0){
        mp[type1] = 1;
        is_res = true;
        type++;
        break;
      }
    }
    if(is_res){
      res -= num + (type-1)*(type-1);
      res += type*type + num1;
      ans = max(res,ans);
    }
    else break;
  }
  out(ans);
}