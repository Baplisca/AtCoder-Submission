#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int n; cin >> n;
    vector<ll> a(n),b(n),c(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll res = 0;
    for(int i=0;i<n;i++){
        auto posa = lower_bound(a.begin(),a.end(),b[i]) - a.begin();
        auto posc = upper_bound(c.begin(),c.end(),b[i]) - c.begin();
        res += posa*(n-posc);
    }

    cout << res << endl;
}