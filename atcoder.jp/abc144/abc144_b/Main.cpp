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
    int n; cin >> n;
    bool res = false;
    rep1(i,n+1){
        if(n%i ==0){
            if(n/i <= 9 && i <= 9)res = true;
        }
    }
    if(res)yes;
    else no;
}
