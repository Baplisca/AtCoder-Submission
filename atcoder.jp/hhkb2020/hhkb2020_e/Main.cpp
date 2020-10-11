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
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//以降 cin の入力元が 'input.txt' になる
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

const ll mod = 1000000007;
 
// aのn乗を求める。計算量はO(logn)
ll modpow(ll a, ll n) {
    if(n == 0) {
        return 1;
    }
    if(n%2 == 1) {
        return (a * modpow(a, n-1))%mod;
    }
    return (modpow(a, n/2) * modpow(a, n/2))%mod;
}
 
signed main() {
    ll h, w;
    cin >> h >> w;
 
    vector<string> board(h);
    rep(i, h) {
        cin >> board[i];
    }
 
    ll k = 0;
    rep(i, h) {
        rep(j, w) {
            if(board[i][j] == '.') {
                k++;
            }
        }
    }
 
    vvl L(h, vl(w));  // L[i][j] : (i,j)の左側の障害物のないマスの連続している個数
    rep(i, h) {
        for(ll j = 1; j < w; j++) {
            if(board[i][j-1] == '#') {
                L[i][j] = 0;
            }
            else {
                L[i][j] = L[i][j-1] + 1;
            }
        }
    }
 
    vvl R(h, vl(w));  // R[i][j] : (i,j)の右側の障害物のないマスの連続している個数
    rep(i, h) {
        for(ll j = w-2; j >= 0; j--) {
            if(board[i][j+1] == '#') {
                R[i][j] = 0;
            }
            else {
                R[i][j] = R[i][j+1] + 1;
            }
        }
    }
 
    vvl U(h, vl(w));  // U[i][j] : (i,j)の上側の障害物のないマスの連続している個数
    for(ll i = 1; i < h; i++) {
        rep(j, w) {
            if(board[i-1][j] == '#') {
                U[i][j] = 0;
            }
            else {
                U[i][j] = U[i-1][j] + 1;
            }
        }
    }
 
    vvl D(h, vl(w));  // D[i][j] : (i,j)の下側の障害物のないマスの連続している個数
    for(ll i = h-2; i >= 0; i--) {
        rep(j, w) {
            if(board[i+1][j] == '#') {
                D[i][j] = 0;
            }
            else {
                D[i][j] = D[i+1][j] + 1;
            }
        }
    }
 
    ll ans = 0;
    rep(i, h) {
        rep(j, w) {
            if(board[i][j] == '#') {
                continue;
            }
            ll x = L[i][j] + R[i][j] + U[i][j] + D[i][j] + 1;
            ans += (modpow(2, k) + mod - modpow(2, k-x))%mod;
            ans %= mod;
        }
    }
    
    out(ans);
}   
