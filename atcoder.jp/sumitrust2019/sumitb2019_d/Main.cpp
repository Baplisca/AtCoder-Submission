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

signed main()
{   
    gearup;
    int n;string s;
    cin >> n >> s;
    ll res = 0;
    rep(i,1000){
        int i3 = i%10;
        int i2 = (i/10)%10;
        int i1 = (i/100);
        //cout << i1 << i2 << i3 << endl;
        bool b1 = false;
        bool b2 = false;
        bool b3 = false;
        rep(j,n){
            if(!b1){
                if((i1 + '0') == (s[j]))b1 = true;
            }
            else if(!b2){
                if((i2 + '0') == (s[j]))b2 = true;
            }
            else if(!b3){
                if((i3 + '0') == (s[j]))b3 = true;
            }
            if(b1 && b2 && b3){
                 res++;
                 break;
            }
        }
    }
    cout << res << endl;
}