#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long INF = 1LL << 60;
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}

signed main()
{   
    gearup;
    ll l,x,y,s,d; cin >> l >> x >> y >> s >> d;
    double res;
    if(s<=d){
        if(y-x>0)res = min((d-s)*1.0/(x+y),(1.0*abs(l-d)+s)/(y-x));
        else res = (d-s)*1.0/(x+y);
    }
    else{
        if(y-x>0) res = min((l-s+d)*1.0/(x+y),(s-d)*1.0/(y-x));
        else res = (l-s+d)*1.0/(x+y);
    }
    cout << fixed << setprecision(7) <<  res << endl;
}
