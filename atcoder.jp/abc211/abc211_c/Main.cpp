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
ll MOD = 1e9 + 7;
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
    string s;
    cin >> s;
    int n = s.size();
    vvl a(n + 1, vl(9));
    a[0][0] = 1;
    rep(i, n) rep(j, 9)
    {
        a[i + 1][j] += a[i][j];
        if (s[i] == 'c' && j == 0)
            a[i + 1][j + 1] += a[i][j];
        if (s[i] == 'h' && j == 1)
            a[i + 1][j + 1] += a[i][j];
        if (s[i] == 'o' && j == 2)
            a[i + 1][j + 1] += a[i][j];
        if (s[i] == 'k' && j == 3)
            a[i + 1][j + 1] += a[i][j];
        if (s[i] == 'u' && j == 4)
            a[i + 1][j + 1] += a[i][j];
        if (s[i] == 'd' && j == 5)
            a[i + 1][j + 1] += a[i][j];
        if (s[i] == 'a' && j == 6)
            a[i + 1][j + 1] += a[i][j];
        if (s[i] == 'i' && j == 7)
            a[i + 1][j + 1] += a[i][j];
        a[i + 1][j] %= MOD;
    }
    out(a[n][8]);
}
