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

signed main()
{
    gearup;
    int m, n;
    cin >> m;
    vpii dests(m);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        dests[i] = {a, b};
    }
    cin >> n;
    map<pair<int, int>, bool> mp;
    vpii exists(n);
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        mp[{a, b}] = true;
        exists[i] = {a, b};
    }
    //dest[0]をexistsで全探索
    rep(i, n)
    {
        int dif_x = exists[i].first - dests[0].first;
        int dif_y = exists[i].second - dests[0].second;
        bool is_res = true;
        rep1(j, m)
        {
            int ex = dests[j].first + dif_x;
            int ey = dests[j].second + dif_y;
            if (mp[{ex, ey}] == false)
                is_res = false;
        }
        if (is_res)
        {
            cout << dif_x << " " << dif_y << endl;
            return 0;
        }
    }
}
