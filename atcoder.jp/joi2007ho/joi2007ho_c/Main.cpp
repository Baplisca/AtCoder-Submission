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

bool exist[5010][5010];
signed main()
{
    gearup;
    int n;
    cin >> n;
    vpii p;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        p.push_back({a, b});
        exist[a][b] = true;
    }
    sort(all(p)); //昇順ソート
    ll res = 0;
    //2点を全探索
    rep(i, n) exrep(j, i + 1, n)
    {
        int x1 = p[i].first;
        int y1 = p[i].second;
        int x2 = p[j].first;
        int y2 = p[j].second;
        int x3 = (y1 - y2) + x1;
        int y3 = (x2 - x1) + y1;
        int x4 = (y1 - y2) + x2;
        int y4 = (x2 - x1) + y2;
        if (x3 < 0 || x4 < 0)
            continue;
        if (x3 > 5000 || y3 > 5000 || x4 > 5000 || y4 > 5000)
            continue;
        if (exist[x3][y3] && exist[x4][y4])
        {
            ll area = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
            res = max(res, area);
        }
    }
    out(res);
}
