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

signed main() {
    gearup;
    ll n,m; cin >> n >> m;
    vl h(n),w(m);
    rep(i,n)cin>>h[i];
    rep(i,m)cin>>w[i];
    sort(all(h));
    sort(all(w));
    //左からの累積和
    vl left_sum((n+1)/2 + 1);
    //右からの累積和
    vl right_sum((n+1)/2 + 1);
    for(int i=0;i<n;i+=2)left_sum[(i/2) + 1] = left_sum[i/2] + h[i+1] - h[i];
    for(int i=n-2;i>0;i-=2)right_sum[i/2] = right_sum[i/2 + 1] + h[i+1] - h[i];

    ll res = L_INF;
    rep(i,m){
        int idx = lower_bound(all(h),w[i]) - h.begin();
        if(idx & 1)idx--;
        ll ans = left_sum[idx/2] + right_sum[idx/2] + abs(h[idx] - w[i]);
        res = min(res,ans);
    }
    out(res);
}   
