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
    int n; cin >> n;
    vs w(n);
    rep(i,n)cin>>w[i];
    map<char,char> mp;
    mp['b'] = '1';
    mp['c'] = '1';
    mp['d'] = '2';
    mp['w'] = '2';
    mp['t'] = '3';
    mp['j'] = '3';
    mp['f'] = '4';
    mp['q'] = '4';
    mp['l'] = '5';
    mp['v'] = '5';
    mp['s'] = '6';
    mp['x'] = '6';
    mp['p'] = '7';
    mp['m'] = '7';
    mp['h'] = '8';
    mp['k'] = '8';
    mp['n'] = '9';
    mp['g'] = '9';
    mp['z'] = '0';
    mp['r'] = '0';
    vs res;
    rep(i,n){
        int m = w[i].size();
        string tmp = "";
        rep(j,m){
            char c = tolower(w[i][j]);
            if(mp[c] != mp['.'])tmp += mp[c];
        }
        if(tmp != "")res.push_back(tmp);
    }
    rep(i,res.size()){
        if(i)cout << " ";
        cout << res[i];
    }
    cout << endl;
}
