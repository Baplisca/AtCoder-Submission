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
    int n,m; cin >> n >> m;
    vector<ll> dp(n+1,0);
    vector<bool> is_safe(n+1,true);

    for(int i=0;i<m;i++){
        int a; cin >> a;
        is_safe[a] = false;
    } 

    dp[0]=1;
    if(is_safe[1])dp[1]=1;

    for(int i=2;i<n+1;i++){
        if(is_safe[i-2])dp[i] += dp[i-2];
        if(is_safe[i-1])dp[i] += dp[i-1];
        dp[i] %= MOD;
    }
    cout << dp[n] << endl;
}