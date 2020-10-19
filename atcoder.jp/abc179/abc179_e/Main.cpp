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
//ll MOD = 1000000007;
ll MOD = 998244353;
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

signed main() {
    gearup;
    ll n,x,m; cin >> n >> x >> m;
    ll res = 0;
    ll a = x;
    res += a;
    vl s; //累積和
    vl A;
    map<int,int> mp; //[数字,数字の出現場所]
    mp[a] = 1;
    s.push_back(0);
    s.push_back(res);
    A.push_back(0);
    A.push_back(a);
    for(ll i = 2;i<=n;i++){
        a = (a*a) % m;
        res += a;
        s.push_back(res);
        A.push_back(a);
        if(mp[a]){
            ll first_idx = mp[a];
            //公差を求める
            ll dif = i - first_idx; //周期
            ll div = (n - first_idx + 1)/dif; //何回周期？
            ll dif_sum = s[i-1] - s[first_idx -1]; //1周期の合計
            res = s[first_idx-1] + div * dif_sum;

            //切り捨てた分足す
            ll mod = (n - first_idx + 1) % dif;
            for(int j=0;j<mod;j++)res += A[j + first_idx];
            out(res);
            return 0;
        }
        else mp[a] = i;
        if(a == 0)break;
    }
    out(res);
}   
