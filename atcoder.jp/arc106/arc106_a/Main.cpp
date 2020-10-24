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

//nの素因数分解する
map<ll,ll> factorize(ll n){
    map<ll,ll> ret;
    ll x = n;
    for(ll i = 2; i*i<=n;i++){
        while(x % i == 0){
            ret[i]++;
            x /= i;
        }
    }
    if(x != 1)ret[x]++;
    return ret;
}

signed main() {
    gearup;
    ll n; cin >> n;
    ll a = 3;
    ll pre_a = a;

    map<ll,int> mp5;
    ll now = 5;
    ll ma = 5;
    rep(i,50){
        mp5[now] = i+1;
        now *= 5;
        if(now < ma)break;
        ma = now;
    }
    ll cnt = 1;
    while(1){
        if(pre_a > a || cnt > 51){
            out(-1);
            return 0;
        }
        ll num = n - a;
        if(num >= 5 && mp5[num]){
            cout << cnt << " ";
            cout << mp5[num] << endl;
            return 0;
        }
        pre_a = a;
        a *= 3;
        cnt++;
    }
    //何もない
    out(-1);

    return 0;
}   
