#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
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

signed main()
{   
    gearup;
    int n,C; cin >> n >> C;
    int num[200010] = {};
    vector<vector<pair<int,int> > > data(C);
    rep(i,n){
        int s,t,c; cin >> s >> t >> c;
        data[--c].push_back({s,t});
    }
    rep(i,C)sort(all(data[i]));

    int ans = 0;
    rep(i,C){
        rep(j,data[i].size()){
        int s = data[i][j].first, t = data[i][j].second;
        //同じチャネルで連続する区間があるか
        while(j < data[i].size() - 1 && data[i][j + 1].first == t) {
            t = data[i][++j].second;
        }
        ++num[s * 2 - 1];
        --num[t * 2];
        }
    }
    for(int i = 1; i <= 200000; ++i) {
        num[i] += num[i - 1];
        ans = max(ans, num[i]);
    }
    out(ans);
}
