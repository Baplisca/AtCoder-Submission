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
const ll cx[6] = {10,-10,5,-5,1,-1};

signed main()
{   
    gearup;
    int n,m; cin >> n >> m;
    vvl fri(n,vl(n,0));
    rep(i,m){
        int x,y; cin >> x >> y;
        x--;y--;
        fri[x][y] = 1;
    }
    ll res = 1;
    for(int i=0;i<(1<<n);i++){
        vector<int> fri_list;
        for(int j=0;j<n;j++){
            if(i & (1<<j)) fri_list.push_back(j);
        }
        bool judge = true;
        ll si = fri_list.size();
        for(int j=0;j<si-1;j++){
            for(int k=j+1;k<si;k++){
                if(fri[fri_list[j]][fri_list[k]] == 0)judge = false;
            }
        }
        if(judge)res = max(res,si);
    }
    cout << res << endl;
}
