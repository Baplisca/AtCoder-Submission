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

typedef long long  ll;
typedef long double ld;
typedef unsigned long long ull;
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
const ll dx[9] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
const ll dy[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};

signed main()
{   
    gearup;
    ll h,w,n; cin >> h >> w >> n;
    map<pair<int,int>,int> mp;
    rep(i,n){
        int a,b; cin >> a >> b;
        rep(j,9){
            int nx = b+dx[j];
            int ny = a+dy[j];
            if(nx >= w || nx <= 1)continue;
            if(ny >= h || ny <= 1)continue;
            mp[pair<int,int>(ny,nx)]++;
        }
    }

    vl num(10);
    num[0] = (w-2)*(h-2);
    for(auto m:mp){
        num[m.second]++;
        num[0]--;
    }
    rep(i,10)out(num[i]);
}