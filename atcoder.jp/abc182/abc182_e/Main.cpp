#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
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
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//以降 cin の入力元が 'input.txt' になる
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

bool is_ramp[1510][1510];
bool is_shogai[1510][1510];
signed main()
{   
    gearup;
    ll h,w,n,m; cin >> h >> w >> n >> m;
    vl a(n),b(n),c(m),d(m);
    rep(i,n){
        cin>>a[i] >> b[i];
        is_ramp[a[i]-1][b[i]-1] = true;
    }
    rep(i,m){
        cin >> c[i] >> d[i];
        is_shogai[c[i]-1][d[i]-1] = true;
    }
 
    vvl l(h,vl(w)),r(h,vl(w)),u(h,vl(w)),D(h,vl(w));
    
    //左を見たときの壁からの距離
    rep(i,h){
        ll num = 0;
        rep(j,w){
            if(is_shogai[i][j])num=0;
            else if(is_ramp[i][j])num++;
            l[i][j] = num;
        }
    }
    rep(i,h){
        ll num = 0;
        for(int j = w-1;j>=0;j--){
            if(is_shogai[i][j])num=0;
            else if(is_ramp[i][j])num++;
            r[i][j] = num;
        }
    }
    rep(j,w){
        ll num = 0;
        rep(i,h){
            if(is_shogai[i][j])num=0;
            else if(is_ramp[i][j])num++;
            u[i][j] = num;
        }
    }
    rep(j,w){
        ll num = 0;
        for(int i = h-1;i>=0;i--){
            if(is_shogai[i][j])num=0;
            else if(is_ramp[i][j])num++;
            D[i][j] = num;
        }
    }
 
    ll res = 0;
    rep(i,h)rep(j,w)if(l[i][j] || r[i][j] || u[i][j] || D[i][j])res++;
    out(res);
}
