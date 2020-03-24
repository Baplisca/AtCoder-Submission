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
    int dp[105][105][105]={0};
    
    //dp[0][0][0] = 0;
    for(int i=0;i<n;i++){
        int a,b,c;
        int w; cin >> a >> b >> c >> w;
        dp[a][b][c]= max(dp[a][b][c],w);
    }
    
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            for(int k=0;k<=100;k++){
                chmax(dp[i+1][j][k],dp[i][j][k]);
                chmax(dp[i][j+1][k],dp[i][j][k]);
                chmax(dp[i][j][k+1],dp[i][j][k]);
            }
        }
    }

    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        cout << dp[x][y][z] << endl;
    }
    return 0;
}
    