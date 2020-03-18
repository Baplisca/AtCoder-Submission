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
    int n; cin >> n;
    vector<ll> dp(n+100000,INF);
    vector<int> c(1,1);
    for(int i=6;i<=100000;i*=6) c.push_back(i);
    for(int i=9;i<=100000;i*=9) c.push_back(i);
    sort(c.begin(),c.end());
    
    dp[0] = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<c.size();j++){
            chmin(dp[i+c[j]],dp[i]+1);
        }
    }
    cout << dp[n] << endl;
}