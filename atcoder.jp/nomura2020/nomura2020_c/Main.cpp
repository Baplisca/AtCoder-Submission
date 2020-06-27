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
const long long L_0 = 1LL << 60;
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

signed main()
{   
    gearup;
    int n; cin >> n;
    vl a(n+1);
    ll sum = 0;
    rep(i,n+1){
        cin >> a[i];
        sum += a[i];
    }
    auto solve = [&]() -> ll{
        if(n == 0){
            if(a[0] == 1)return 1;
            else return -1;
        }
        if(a[0] != 0)return -1;
        ll now = 1; //現在の深さのノード、最初はノード1個
        ll res = 1;
        //Greedyに残り葉の分だけ、葉を増やす
        rep(i,n){
            now -= a[i]; //高さiの葉分だけ消す
            sum -= a[i]; //残りの葉の総数
            if(now <= 0)return -1;
            if(now*2 <= sum)
                now *= 2;
            else if(now < sum)
                now += sum - now;
            res += now;
        }
        if(now < a[n])return -1;
        return res;
    };
    out(solve());
}

