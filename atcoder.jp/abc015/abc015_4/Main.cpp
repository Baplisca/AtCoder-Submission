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
    int w,n,K; cin >> w >> n >> K;
    vector<ll> width(n);
    vector<ll> value(n);
    for(int i=0;i<n;i++) cin >> width[i] >> value[i];

    //wとkの制約を守りながらDPする
    //dp[商品N][枚数K][幅W]
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(K + 1, vector<ll>(w + 1)));

    dp[0][0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=K;j++){
            for(int k=0;k<=w;k++){
                if(k - width[i-1] >= 0)
                    chmax(dp[i][j][k],dp[i-1][j-1][k-width[i-1]] + value[i-1]);
                chmax(dp[i][j][k],dp[i-1][j][k]);
            }
        }
    }
    cout << dp[n][K][w] << endl;
}
    