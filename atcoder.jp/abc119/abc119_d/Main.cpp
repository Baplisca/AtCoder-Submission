#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << end
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

signed main()
{   
    gearup;
    int a,b,q;cin >> a >> b >> q;
    vl s(a+2,L_INF),t(b+2,L_INF);
    s[0]=-L_INF;t[0]=-L_INF;
    rep1(i,a+1) cin >> s[i];
    rep1(i,b+1) cin >> t[i];
    rep(i,q){
        ll x; cin >> x;
        ll s_idx = lower_bound(all(s),x) - s.begin();
        ll t_idx = lower_bound(all(t),x) - t.begin();
        ll res = L_INF;
        for(int j=s_idx-1;j<= s_idx;j++){
            for(int k=t_idx-1;k<= t_idx;k++){
                res = min(res,abs(x-s[j])+abs(s[j]-t[k]));
                res = min(res,abs(x-t[k])+abs(s[j]-t[k]));
            }
        }
        cout << res << endl;
    }
}
