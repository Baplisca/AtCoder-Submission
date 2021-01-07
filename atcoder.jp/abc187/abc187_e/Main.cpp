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
ll pcount(ll x) { return __builtin_popcountll(x); }
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//以降 cin の入力元が 'input.txt' になる
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

signed main()
{
    gearup;
    int n;
    cin >> n;
    vl a(n - 1), b(n - 1);
    vvl edge(n);
    rep(i, n - 1)
    {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        edge[a[i]].push_back(b[i]);
        edge[b[i]].push_back(a[i]);
    }
    vl dists(n, L_INF);
    function<void(int, int, int)> dfs = [&](int node, int pre_node, int depth) {
        dists[node] = depth;
        for (auto nv : edge[node])
        {
            if (nv == pre_node)
                continue; //逆流防止
            dfs(nv, node, depth + 1);
        }
    };
    //ノード0を根とした木を生成
    dfs(0, -1, 0);

    int q;
    cin >> q;
    vl costs(n);
    rep(i, q)
    {
        int t, e, x;
        cin >> t >> e >> x;
        e--;
        int node_A = a[e];
        int node_B = b[e];
        if (t == 2)
            swap(node_A, node_B);

        //node_Bを通らないようにする
        if (dists[node_A] < dists[node_B])
        {
            costs[0] += x;
            costs[node_B] -= x;
        }
        else
        {
            costs[node_A] += x;
        }
    }
    vb visited(n);
    queue<int> que;
    que.push(0);
    visited[0] = true;
    vl res(n);
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        res[node] = costs[node];
        for (auto nv : edge[node])
        {
            if (visited[nv])
                continue;
            visited[nv] = true;
            costs[nv] += costs[node];
            que.push(nv);
        }
    }
    rep(i, n) out(res[i]);
}
