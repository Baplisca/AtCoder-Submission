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

typedef complex<double> cp;

double distance(cp p0, cp c1, cp c2){
    // c1原点に移動
    p0 -= c1;
    c2 -= c1;
 
    // 回転
    auto u = c2 / abs(c2);
    p0 /= u;
 
    return p0.imag();
}

//参考　https://perogram.hateblo.jp/entry/arc042_b
//考察　垂線が引けないところが最短になることはない
signed main() {
    gearup;
    int X,Y; cin >> X >> Y;
    cp Z(X,Y);
    int n; cin >> n;
    vector<cp> z(n);
    vl x(n),y(n);
    rep(i,n){
        cin>>x[i]>>y[i];
        z[i].real(x[i]);
        z[i].imag(y[i]);
    }
    double res = INF;
    rep(i,n){
        double d = distance(Z, z[i], z[(i+1) % n]);
        res = min(res,d);
    }
    cout << fixed << setprecision(15);
    out(res);
}   
