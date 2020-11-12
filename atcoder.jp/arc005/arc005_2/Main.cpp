#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<bool> > vvb;
typedef vector<vector<double> > vvd;
typedef vector<vector<string> > vvs;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
ll pcount(ll x) {return __builtin_popcountll(x);}
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//以降 cin の入力元が 'input.txt' になる
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

signed main()
{   
    gearup;
    int x,y;
    string W; cin >> x >> y >> W;
    x--;y--;
    vs s(9);
    rep(i,9)cin>>s[i];
    vvl a(9,vl(9));
    rep(i,9)rep(j,9)a[i][j] = s[i][j] - '0';
    string res = "";
    res += a[y][x] + '0';
    map<string,int> mp;
    mp["R"] = 0;
    mp["L"] = 4;
    mp["U"] = 6;
    mp["D"] = 2;
    mp["RU"] = 7;
    mp["RD"] = 1;
    mp["LU"] = 5;
    mp["LD"] = 3;
    int now = mp[W];
    vl dx = {1, 1, 0, -1, -1, -1, 0, 1};
    vl dy = {0, 1, 1, 1, 0, -1, -1, -1};
    
    rep(i,3){
        int nx = x + dx[now];
        int ny = y + dy[now];

        if(nx < 0 || nx >= 9){
            dx[now] = -dx[now];
        }
        if(ny < 0 || ny >= 9){
            dy[now] = -dy[now];
        }
        x += dx[now];
        y += dy[now];
        res += a[y][x] + '0';
    }
    out(res);
}
