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

// a^b mod を計算する
ll mod_pow(ll a, ll b, ll p)
{
    if (b == 0)
        return 1;
    if (b & 1)
        return (a * mod_pow(a, b - 1, p));
    ll t = mod_pow(a, b / 2, p);
    return (t * t);
}

signed main()
{
    gearup;
    ll k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    vl num(10, k);
    vl num_a(10);
    vl num_b(10);
    int n = 5;
    rep(i, n - 1)
    {
        int nu1 = s[i] - '0';
        int nu2 = t[i] - '0';
        num[nu1]--;
        num[nu2]--;
        num_a[nu1]++;
        num_b[nu2]++;
    }
    //全探索
    ll a, b;
    a = b = 0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            auto nums = num;
            nums[i]--;
            nums[j]--;
            //試合が成立しない
            if (nums[i] < 0 || nums[j] < 0)
                continue;
            //得点計算
            auto num_A = num_a;
            auto num_B = num_b;
            num_A[i]++;
            num_B[j]++;
            ll sco_a = 0;
            ll sco_b = 0;
            for (int ii = 1; ii <= 9; ii++)
            {
                sco_a += ii * mod_pow(10, num_A[ii], MOD);
                sco_b += ii * mod_pow(10, num_B[ii], MOD);
            }
            //これが起こる通り 9*k - 8枚から選ぶ
            auto NUMS = num;
            ll A = NUMS[i]--;
            ll B = NUMS[j]--;
            ll sum = A * B;
            if (sco_a > sco_b)
                a += sum;
            else
                b += sum;
        }
    }
    cout << fixed << setprecision(10);
    cout << a * 1.0 / (a + b) << endl;
}
