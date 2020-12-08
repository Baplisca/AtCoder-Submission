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
ll MOD = 1000000007;
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
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//以降 cin の入力元が 'input.txt' になる
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

signed main()
{
    gearup;
    int n;
    string t;
    cin >> n >> t;
    if (t == "1")
    {
        ll res = pow(10, 10) * 2;
        out(res);
        return 0;
    }
    if (t == "11")
    {
        ll res = pow(10, 10);
        out(res);
        return 0;
    }

    //最初が110から始まる
    bool ischeck1 = true;
    for (int i = 0; i < n; i += 3)
    {
        if (t[i] != '1')
            ischeck1 = false;
        if (i + 1 >= n)
            continue;
        if (t[i + 1] != '1')
            ischeck1 = false;
        if (i + 2 >= n)
            continue;
        if (t[i + 2] != '0')
            ischeck1 = false;
    }
    //最初が101から始まる
    bool ischeck2 = true;
    for (int i = 0; i < n; i += 3)
    {
        if (t[i] != '1')
            ischeck2 = false;
        if (i + 1 >= n)
            continue;
        if (t[i + 1] != '0')
            ischeck2 = false;
        if (i + 2 >= n)
            continue;
        if (t[i + 2] != '1')
            ischeck2 = false;
    }
    //最初が011から始まる
    bool ischeck3 = true;
    for (int i = 0; i < n; i += 3)
    {
        if (t[i] != '0')
            ischeck3 = false;
        if (i + 1 >= n)
            continue;
        if (t[i + 1] != '1')
            ischeck3 = false;
        if (i + 2 >= n)
            continue;
        if (t[i + 2] != '1')
            ischeck3 = false;
    }
    if (ischeck1 || ischeck2 || ischeck3)
    {
        int zero_cnt = 0;
        rep(i, n) if (t[i] == '0') zero_cnt++;
        ll res = pow(10, 10) - zero_cnt;
        if (t[n - 1] == '0')
            res++;
        out(res);
    }
    else
    {
        out(0);
    }
}
