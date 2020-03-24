#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{   
    ll n,m; cin >> n >> m;
    vector<ll> a(n),b(n);
    vector<vector<ll>> c(n,vector<ll>(2));
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        c[i][0] = a[i];
        c[i][1] = b[i];
    }
    sort(c.begin(),c.end());
    ll res = 0;
    ll count = 0;
    for(int i=0;i<n;i++){
        while(c[i][1] > 0){
            res += c[i][0];
            c[i][1]--;
            count++;
            if(count >= m){
                cout << res << endl;
                return 0;
            }
        }
    }
}
    