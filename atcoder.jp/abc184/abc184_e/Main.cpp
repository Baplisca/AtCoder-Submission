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
    int h, w;
    cin >> h >> w;
    vs a(h);
    rep(i, h) cin >> a[i];
    vector<vpii> p(26);
    pair<int, int> S;
    rep(i, h) rep(j, w)
    {
        if (a[i][j] >= 'a' && a[i][j] <= 'z')
            p[a[i][j] - 'a'].push_back({i, j});
        if (a[i][j] == 'S')
            S.first = i, S.second = j;
    }
    vvb visited(h, vb(w));
    vb char_visited(26, false);
    vvl dests(h, vl(w, INF));
    visited[S.first][S.second] = true;
    dests[S.first][S.second] = 0;
    queue<pair<int, int>> deq;
    deq.push(S);
    while (deq.empty() == false)
    {
        int x = deq.front().first;
        int y = deq.front().second;
        deq.pop();
        for (int i = 0; i < 8; i += 2)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if (visited[nx][ny])
                continue;
            if (a[nx][ny] == '#')
                continue;
            if (a[nx][ny] == '.' || a[nx][ny] >= 'a' && a[nx][ny] <= 'z')
            {
                visited[nx][ny] = true;
                dests[nx][ny] = dests[x][y] + 1;
                deq.push({nx, ny});
            }
            else if (a[nx][ny] == 'G')
            {
                out(dests[x][y] + 1);
                return 0;
            }
        }
        if (islower(a[x][y]))
        {
            int idx = a[x][y] - 'a';
            if (char_visited[idx])
                continue;
            char_visited[idx] = true;
            rep(j, p[idx].size())
            {
                int ex = p[idx][j].first;
                int ey = p[idx][j].second;
                if (visited[ex][ey] == false)
                {
                    visited[ex][ey] = true;
                    dests[ex][ey] = dests[x][y] + 1;
                    deq.push({ex, ey});
                }
            }
        }
    }
    out(-1);
}
