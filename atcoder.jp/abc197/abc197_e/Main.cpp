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
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

signed main()
{
    gearup;
    int n;
    cin >> n;
    vvl a(n + 1);
    rep(i, n)
    {
        int x, c;
        cin >> x >> c;
        a[c].push_back(x);
    }
    rep(i, n + 1) sort(all(a[i]));
    vvl dp(n + 1, vl(2, L_INF));
    dp[0][0] = dp[0][1] = 0;
    int l = 0, r = 0;
    rep1(i, n + 1)
    {
        if (a[i].size() == 0)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
        }
        else
        {
            int m = a[i].size();
            int next_l = a[i][0];
            int next_r = a[i][m - 1];
            //next_rに行ってから、next_lへ
            if (r >= next_r)
                dp[i][0] = min(dp[i][0], dp[i - 1][1] + r - next_l);
            else
                dp[i][0] = min(dp[i][0], dp[i - 1][1] + next_r - r + next_r - next_l);
            if (l >= next_r)
                dp[i][0] = min(dp[i][0], dp[i - 1][0] + l - next_l);
            else
                dp[i][0] = min(dp[i][0], dp[i - 1][0] + next_r - l + next_r - next_l);

            //next_lからnext_rへ
            if (r <= next_l)
                dp[i][1] = min(dp[i][1], dp[i - 1][1] + next_r - r);
            else
                dp[i][1] = min(dp[i][1], dp[i - 1][1] + r - next_l + next_r - next_l);
            if (l <= next_l)
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + next_r - l);
            else
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + l - next_l + next_r - next_l);
            l = next_l;
            r = next_r;
        }
    }
    ll res = min(dp[n][1] + abs(r), dp[n][0] + abs(l));
    out(res);
}
