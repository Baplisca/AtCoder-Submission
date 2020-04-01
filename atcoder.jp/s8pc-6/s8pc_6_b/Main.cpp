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

signed main()
{   
    gearup;
    int n; cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    auto c = a;
    auto d = b;
    sort(all(c));
    sort(all(d));
    ll ave_a,ave_b;
    if(n%2){
         ave_a = c[n/2];
         ave_b = d[n/2];
    }
    else{
        ave_a = (c[n/2-1] + c[n/2]) /2;
        ave_b = (d[n/2-1] + d[n/2]) /2;
    }
    ll res = 0;
    rep(i,n){
        res += abs(a[i]-ave_a);
        res += abs(b[i]-ave_b);
        res += abs(b[i] - a[i]);
    }
    cout << res << endl;
}