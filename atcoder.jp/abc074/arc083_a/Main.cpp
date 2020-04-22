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

signed main(){
    gearup;
    ll a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
    ll res_suwa = 0,res_su = 0;
    double rate = 0.0;
    rep(i,31){ //100*a*i
        rep(j,31){ //100*b*j
            for(int k=0;k<= f/c;k++){ //c*k
                for(int l=0;l<=f/d;l++){ //d*l
                    ll wa = 100*(a*i+b*j);
                    ll su = c*k + d*l;
                    if(wa+su > f)continue;
                    if(su*1.0/(wa+su) > e*1.0/(100+e))continue;
                    if(rate > su*1.0/(wa+su))continue;
                    rate = su*1.0/(wa+su);
                    res_suwa = su+wa;
                    res_su = su;
                }
            }
        }
    }
    if(rate == 0.0){
        cout << 100*a << " " << 0 << endl;
        return 0;
    }
    cout << res_suwa << " " << res_su << endl;
}

