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
    gearup;
    ll n; cin >> n;
    ll table[1000010] = {0};
    ll a,b;

    rep(i,n){
        cin >> a >> b;
        table[a]++;
        table[b+1]--;
    }
    //いもす法
    rep(i,1000001){
        table[i+1] += table[i];
    }
    ll res = 0;
    rep(i,1000001)res = max(res,table[i]);
    cout << res << endl;
}
