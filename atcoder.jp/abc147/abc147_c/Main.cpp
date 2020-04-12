#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<ll, ll> P;
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

int n;
vector<vector<pair<int,int> > > p(15);
bool judge(int bit){
    for(int i=0;i<n;i++){ //n人について調べる
        if( !(bit & (1<<i)))continue;
        for(auto z:p[i]){
            int X = z.first;
            int Y = z.second; //Yが1ならXは本当

            if(Y==1) if(!(bit & (1<<X))) return false;
            if(Y==0) if(bit & (1<<X)) return false;
        }
    }
    return true;
}
signed main()
{   
    gearup;
    cin >> n;
    rep(i,n){
        int a; cin >> a;
        rep(j,a){
            int x,y; cin >> x >> y;x--;
            p[i].push_back(make_pair(x,y));
        }
    }
    ll res = 0;
    //ビット全探索 正直者を1とする
    for(int bit=0;bit<(1<<n);bit++){

        if(judge(bit)){
            ll cnt = 0;
            rep(j,n) if(bit & (1<<j)) cnt++;
            res = max(res,cnt);
        }
    }
    cout << res << endl;
}
