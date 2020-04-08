#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<ll, ll> P;
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
    int x1,y1,r; cin >> x1 >> y1 >> r;
    int x2,y2,x3,y3; cin >> x2 >> y2 >> x3 >> y3;
    if(x1-r < x2 || x1+r > x3 || y1 - r < y2 || y1 +r > y3)cout << "YES" << endl;
    else cout << "NO" << endl;
    bool is_res = false;
    if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) > r*r) is_res = true;
    if((x1-x2)*(x1-x2)+(y1-y3)*(y1-y3) > r*r) is_res = true;
    if((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3) > r*r) is_res = true;
    if((x1-x3)*(x1-x3)+(y1-y2)*(y1-y2) > r*r) is_res = true;
    if(is_res) cout << "YES" << endl;
    else cout << "NO" << endl;
}
