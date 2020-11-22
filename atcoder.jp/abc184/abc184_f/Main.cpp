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
    ll n, t;
    cin >> n >> t;
    vl b, c;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (i < n / 2)
            b.push_back(a);
        else
            c.push_back(a);
    }

    vl bb, cc;
    int bsize = b.size();
    rep(i, 1 << bsize)
    {
        int sum = 0;
        rep(j, bsize)
        {
            if ((i >> j) & 1)
                sum += b[j];
        }
        bb.push_back(sum);
    }
    int csize = c.size();
    rep(i, 1 << csize)
    {
        int sum = 0;
        rep(j, csize)
        {
            if ((i >> j) & 1)
                sum += c[j];
        }
        cc.push_back(sum);
    }
    sort(all(bb));
    sort(all(cc));
    //debug(bb);
    //debug(cc);
    ll res = 0;
    rep(i, bb.size())
    {
        //t以下
        // 残りの数
        int nokori = t - bb[i];
        ll ma = cc.size(), mi = -1;
        while (ma - mi > 1)
        {
            ll mid = (ma + mi) / 2;
            if (cc[mid] > nokori)
                ma = mid;
            else
                mi = mid;
        }
        int score = cc[mi] + bb[i];
        //out(score);
        if (score <= t)
            res = max(res, score);
    }
    out(res);
}
