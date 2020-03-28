#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int k,n; cin >> k >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    ll res = 0;
    rep(i,n-1){
        res = max(res,1LL*abs(a[i]-a[i+1]));
    }
    res = max(res,1LL*(k-a[n-1]+a[0]));
    cout << k-res << endl;
}
