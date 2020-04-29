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


template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

signed main()
{   
    gearup;
    ll n,c; cin >> n >> c;
    vl x(n),v(n);
    rep(i,n)cin >> x[i] >> v[i];

    vl dp1(n);//時計回りの累積和(カロリー)
    dp1[0] = v[0]-x[0];
    exrep(i, 1, n) dp1[i] = dp1[i-1] + v[i] - (x[i] - x[i-1]);
    exrep(i, 1, n) chmax(dp1[i], dp1[i-1]);

    vl dp2(n);//逆方向の累積和
    dp2[n-1] = v[n-1] - (c - x[n-1]);
    for(int i=n-2;i>=0;i--) dp2[i] = dp2[i+1] + v[i] - (x[i+1] - x[i]);
    for(int i=n-2; i>=0; --i) dp2[i] = max(dp2[i], dp2[i+1]);

    ll res = 0;
    rep(i, n) {
        // i番目まで時計回りで取る
        ll tmp = dp1[i];
        // [i+1, n-1] の最大
        if(i+1<n && dp2[i+1] - x[i] > 0) tmp += dp2[i+1] - x[i];
        chmax(res, tmp);
    }
    for(int i=n-1; i>=0; --i) {
        ll tmp = dp2[i];
        if(i >= 1 && dp1[i-1] - (c - x[i]) > 0 ) tmp += dp1[i-1] - (c - x[i]);
        chmax(res, tmp);
    }
    cout << res << endl;
}
