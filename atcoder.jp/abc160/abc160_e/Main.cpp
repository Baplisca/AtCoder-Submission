#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll MOD = 1000000007;
const long long INF = 1LL << 60;
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

signed main()
{   
    //gearup;
    ll x,y,a,b,c; cin >> x >> y >> a >> b >> c;
    vector<ll> p(a),q(b),r(c);
    rep(i,a) cin >> p[i];
    rep(i,b) cin >> q[i];
    rep(i,c) cin >> r[i];
    sort(all(p),greater<ll>());
    sort(all(q),greater<ll>());
    rep(i,x) r.push_back(p[i]);
    rep(i,y) r.push_back(q[i]);
    sort(all(r),greater<ll>());

    ll res = 0;
    rep(i,x+y) res += r[i];
    cout << res << endl;
}
