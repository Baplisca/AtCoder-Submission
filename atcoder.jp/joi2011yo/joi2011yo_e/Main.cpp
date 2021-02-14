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
    int h, w;
    char n;
    cin >> h >> w >> n;
    vvc c(h, vc(w));
    int sx, sy;
    rep(i, h) rep(j, w)
    {
        cin >> c[i][j];
        if (c[i][j] == 'S')
            sx = i, sy = j;
    }
    char now = '1';
    deque<pair<int, int>> deq;
    deq.push_back({sx, sy});
    vvl dists(h, vl(w, -1));
    dists[sx][sy] = 0;
    while (deq.size())
    {
        int x = deq.front().first;
        int y = deq.front().second;

        deq.pop_front();
        for (int i = 0; i < 8; i += 2)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if (c[nx][ny] == 'X')
                continue;
            if (c[nx][ny] == n && now == n)
            {
                out(dists[x][y] + 1);
                return 0;
            }
            else if (c[nx][ny] == now)
            {
                int tmp = dists[x][y] + 1;
                dists = vector<vector<ll>>(h, vector<ll>(w, -1));
                dists[nx][ny] = tmp;
                now++;
                deq.clear();
                deq.push_back({nx, ny});
                break;
            }
            else if (dists[nx][ny] == -1)
            {
                dists[nx][ny] = dists[x][y] + 1;
                deq.push_back({nx, ny});
            }
        }
    }
}
