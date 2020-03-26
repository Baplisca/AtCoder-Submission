#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int n;string s;
    cin >> n >> s;
    int dp[51]={0};
    for(int i=0;i+2<s.size();i++){
        string sub = s.substr(i,3);
        if(sub == "ABC")dp[i+1]=dp[i]+1;
        else dp[i+1]=dp[i];
    }
    cout << dp[s.size()-2] << endl;
}
    