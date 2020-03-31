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
    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];

    // 二次元累積和
    vector<vector<int> > s(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];

    vector<long long> val(n*n+1, 0); // val[v] := 面積が v の長方形領域の総和の最大値
    for (int x1 = 0; x1 < n; ++x1) {
        for (int x2 = x1 + 1; x2 <= n; ++x2) {
            for (int y1 = 0; y1 < n; ++y1) {
                for (int y2 = y1 + 1; y2 <= n; ++y2) {
                    long long area = (x2 - x1) * (y2 - y1);
                    long long sum = s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
                    val[area] = max(val[area], sum);
                }
            }
        }
    }
    // ちゃんと集計,  val[v] := 面積が v 「以下」の長方形領域の総和の最大値
    for (int v = 0; v < n*n; ++v) val[v+1] = max(val[v+1], val[v]);

    // クエリに答える
    int Q; cin >> Q;
    for (int q = 0; q < Q; ++q) {
        long long P; cin >> P;
        cout << val[P] << endl;
    }
}