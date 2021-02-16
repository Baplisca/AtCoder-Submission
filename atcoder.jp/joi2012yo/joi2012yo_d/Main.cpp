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

int dp[110][5][5]; //dp[i][j][k]: i日目でkの種類を選んで、i-1日目にjを頼んだ時の組み合わせ
signed main()
{
    gearup;
    int n, k;
    cin >> n >> k;
    vl menu(n, -1);
    rep(i, k)
    {
        int a, b;
        cin >> a >> b;
        menu[--a] = --b;
    }
    rep(j, 3) rep(k, 3)
    {
        if (menu[0] != -1 && menu[1] != -1)
            dp[2][menu[0]][menu[1]] = 1;
        else if (menu[0] != -1)
            dp[2][menu[0]][k] = 1;
        else if (menu[1] != -1)
            dp[2][j][menu[1]] = 1;
        else
            dp[2][j][k] = 1;
    }

    for (int i = 2; i < n; i++)
    {
        rep(j, 3)
        {
            rep(k, 3)
            {
                if (menu[i] != -1)
                {
                    if (!(j == k && k == menu[i] && menu[i] == j))
                    {
                        dp[i + 1][k][menu[i]] += dp[i][j][k];
                        dp[i + 1][k][menu[i]] %= 10000;
                    }
                }
                else
                {
                    //次にどのメニューを選ぶか
                    rep(kk, 3)
                    {
                        if (!(j == k && k == kk && kk == j))
                        {
                            dp[i + 1][k][kk] += dp[i][j][k];
                            dp[i + 1][k][kk] %= 10000;
                        }
                    }
                }
            }
        }
    }
    ll res = 0;
    rep(j, 3) rep(k, 3) res += dp[n][j][k];
    out(res % 10000);
}
