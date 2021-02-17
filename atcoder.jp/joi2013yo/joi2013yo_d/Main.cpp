#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i < n; ++i)
#define exrep(i, a, b) for (ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef vector<vector<double>> vvd;
typedef vector<vector<string>> vvs;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
ll MOD = 998244353;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
void debug(T v)
{
    rep(i, v.size()) cout << v[i] << " ";
    cout << endl;
}
ll pcount(ll x) { return __builtin_popcountll(x); }
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//以降 cin の入力元が 'input.txt' になる
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

int dp[210][210][210]; //dp[i][j][k]: i日目でkの種類を選んで、i-1日目にjを頼んだ時の組み合わせ
signed main()
{
    gearup;
    int n, d;
    cin >> n >> d;
    vl t(n);
    rep(i, n) cin >> t[i];
    vl a(d), b(d), c(d);
    rep(i, d) cin >> a[i] >> b[i] >> c[i];
    rep1(i, n) rep(j, d) rep(k, d)
    {
        if (a[k] <= t[i] && t[i] <= b[k] && a[j] <= t[i - 1] && t[i - 1] <= b[j])
        {
            rep(p, d)
            {
                chmax(dp[i + 1][j][k], dp[i][p][j] + abs(c[k] - c[j]));
            }
        }
        else
            dp[i + 1][j][k] = 0;
    }
    ll res = 0;
    rep(j, d) rep(k, d) chmax(res, dp[n][j][k]);
    out(res);
}
