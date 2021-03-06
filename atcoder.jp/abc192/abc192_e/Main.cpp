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

struct Edge
{
    long long to;
    long long cost;
    long long K;
};
using Graph = vector<vector<Edge>>;
using P = pair<long long, int>;
Graph G;

void dijkstra(const Graph &G, int sv, vl &dis)
{
    int N = G.size();
    dis.resize(N, L_INF);
    priority_queue<P, vector<P>, greater<P>> pq; // (仮の最短距離, 頂点)で昇順ソート
    dis[sv] = 0;
    pq.emplace(dis[sv], sv);
    while (!pq.empty())
    {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first)
        { // 最小値を取り出し、それが最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v])
        {
            ll diff = (dis[v] + e.K - 1) / e.K * e.K + e.cost;
            if (dis[e.to] > diff)
            { // 最短距離候補なら追加
                dis[e.to] = diff;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

signed main()
{
    gearup;
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--, y--;
    vl a(m), b(m), t(m), k(m);
    G.resize(n);
    rep(i, m)
    {
        cin >> a[i] >> b[i] >> t[i] >> k[i];
        a[i]--, b[i]--;
        G[a[i]].push_back({b[i], t[i], k[i]});
        G[b[i]].push_back({a[i], t[i], k[i]});
    }
    vl dist;
    dijkstra(G, x, dist); //ノードxからスタート

    if (dist[y] == L_INF)
        out(-1);
    else
        out(dist[y]);
}
