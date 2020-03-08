#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

int main() {
    int n,m; cin >> n >> m;
    if(abs(n-m) > 1){
        cout <<"0"<<endl;
        return 0;
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++) ans = ans * i % MOD;
    for (int i = 1; i <= m; i++) ans = ans * i % MOD;
    cout << ans * ((n == m) + 1) % MOD << endl;
}   

