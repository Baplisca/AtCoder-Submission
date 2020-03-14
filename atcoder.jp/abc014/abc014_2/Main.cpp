#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

int main() {
    int n,X; cin >> n >> X;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int sum = 0;
    for(int i=0;i < n;i++){
        if(X & (1<<i))sum+=a[i];
    }
    cout << sum << endl;
}   
