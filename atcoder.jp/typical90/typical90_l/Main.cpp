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

struct UnionFind
{
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<ll> siz;  // 素集合のサイズを表す配列(1 で初期化)

    UnionFind(int N) : par(N), siz(N)
    { //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++)
        {
            par[i] = i;
            siz[i] = 1;
        }
    }

    int root(int x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {                     // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry)
            return; //xとyの根が同じ(=同じ木にある)時はそのまま
        // merge technique（小を大にくっつける）
        if (siz[rx] < siz[ry])
            swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
    }

    bool same(int x, int y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    ll size(ll x)
    {
        return siz[root(x)];
    }
};

signed main()
{
    gearup;
    int h, w;
    cin >> h >> w;
    UnionFind uf(h * w);
    vvb red(h, vb(w));
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int r, c;
            cin >> r >> c;
            r--, c--;
            red[r][c] = true;
            if (red[max(r - 1, 0LL)][c])
                uf.unite(r * w + c, max(r - 1, 0LL) * w + c);
            if (red[r][max(c - 1, 0LL)])
                uf.unite(r * w + c, r * w + max(c - 1, 0LL));
            if (red[r][min(c + 1, w - 1)])
                uf.unite(r * w + c, r * w + min(c + 1, w - 1));
            if (red[min(r + 1, h - 1)][c])
                uf.unite(r * w + c, min(r + 1, h - 1) * w + c);
        }
        else
        {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--, ca--, rb--, cb--;
            if (red[ra][ca] && red[rb][cb] && uf.same(ra * w + ca, rb * w + cb))
                out("Yes");
            else
                out("No");
        }
    }
}
