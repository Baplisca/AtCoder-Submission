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
  ll n; cin >> n;
  vvl G(n);
  vpii e_in;
  map<pair<int,int> ,int > e_out;
  rep(i,n-1){
    int a,b; cin >> a >> b;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    e_in.emplace_back(a,b);
  }

  vector<set<int> > used(n);
  vb visited(n);
  int max_num = 1;
  queue<int> que;
  que.push(0);
  visited[0]=true;
  //ノードについて見ていき、隣接ノードが使っていない色を埋める
  while(!que.empty()){
    int num = 1; //辺の色は1から
    int v = que.front();
    que.pop();
    for(auto nv:G[v]){
      if(!visited[nv]){
        //vが使っている色は使えない
        if(used[v].find(num) != used[v].end()){
          num++;
        }
        int a = min(nv,1LL*v);
        int b = max(nv,1LL*v);
        e_out[{a,b}] = num;
        used[a].insert(num);
        used[b].insert(num);
        visited[nv]=true;
        que.push(nv);
        num++;
      }
    }
    max_num = max(max_num,num-1);
  }
  //出力
  out(max_num);
  for(auto e:e_in){
    out(e_out[e]);
  }
}