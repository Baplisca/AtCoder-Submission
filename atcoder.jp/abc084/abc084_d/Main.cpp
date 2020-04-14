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

bool is_prime(ll n){
    for(ll i=2;i*i<=n;i++)if(n%i == 0)return false;
    return true;
}
signed main()
{   
    gearup;
    int q; cin >> q;
    int num = 100010;
    vector<int> a(num,0);
    for(int i=3;i<num;i+=2){
        if(is_prime(i) && is_prime((i+1)/2))a[i] = 1;
    }
    vl s(num);
    rep(i,num)s[i+1] = a[i]+s[i];
    rep(i,q){
        int l,r; cin >> l >> r;
        cout << s[r+1] - s[l] << endl;
    }
}
