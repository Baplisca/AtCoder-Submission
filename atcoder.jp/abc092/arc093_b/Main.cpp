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
    int h = 100,w = 100;
    ll a,b; cin >> a >> b;
    vvc c(h,vc(w,'.'));
    rep(i,50)rep(j,w)c[i][j] = '#';

    //aが白'.'の連結部分,a-1個分だけ(最大499個)
    rep(i,a-1){
        int row = (i / 50) * 3;
        int col = (i % 50)*2 + (row % 2);
        c[row][col] = '.';
    }

    //b-1個分黒くする
    rep(i,b-1){
        int row = 99 - (i / 50) * 3;
        int col = (i % 50)*2 + (row % 2);
        c[row][col] = '#';
    }

    //出力
    cout << h << " " << w << endl;
    rep(i,h){
        rep(j,w){
            cout << c[i][j];
        }   
        cout << endl;
    }
}
