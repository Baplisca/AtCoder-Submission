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
    int n,x,y; cin >> n >> x >> y;
    map<int,ll> mp;
    for(int i=1;i<= n;i++){
        for(int j=i+1;j<= n;j++){
            int res = min(j-i,abs(x-i)+abs(y-j)+1);
            mp[res]++;
        }
    }
    for(int k=1;k<n;k++) cout << mp[k] << endl;
}
    