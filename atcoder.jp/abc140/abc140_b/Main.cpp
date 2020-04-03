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

#define MAX 500000
int L[MAX/2 + 2], R[MAX/2 + 2];
int cnt;


signed main()
{   
    gearup;
    int n; cin >> n;
    vl a(n),b(n),c(n-1);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n-1) cin >> c[i];
    ll res = b[a[0]-1];
    ll pre = a[0] - 1;
    rep1(i,n){
        res += b[a[i]-1];
        if(pre+1 == a[i] -1) res+=c[pre];
        pre = a[i] -1;
    }
    cout << res << endl;
}