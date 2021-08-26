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
    int n;
    cin >> n;
    vvl a(n, vl(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    int m;
    cin >> m;
    vvb ng(n, vb(n));
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        ng[x][y] = true;
        ng[y][x] = true;
    }
    vl b(n);
    rep(i, n) b[i] = i;
    ll res = INF;
    do
    {
        ll ttl = 0;
        vl turn(n); //turn[i]:i番目の走者の番号
        rep(i, n)
        {
            ttl += a[i][b[i]];
            turn[b[i]] = i;
        }
        rep(i, n - 1)
        {
            int from = turn[i];
            int to = turn[i + 1];
            if (ng[from][to])
                ttl += INF;
        }
        chmin(res, ttl);
    } while (next_permutation(all(b)));
    if (res == INF)
        out(-1);
    else
        out(res);
}
