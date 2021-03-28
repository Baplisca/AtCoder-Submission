#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    long long res = 1LL << 60;
    for(int i=0;i<(1<< (n-1) );i++){
        long long cur = 0;
        long long ans = 0;
        for(int j=0;j<n;j++){
            cur |= a[j];
            if( (i >> j) & 1){
                ans ^= cur;
                cur = 0;
            }
        }
        ans ^= cur;
        res = min(res,ans);
    }
   cout << res << endl;
}