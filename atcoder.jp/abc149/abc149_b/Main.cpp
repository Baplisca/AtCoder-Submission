#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a,b,k; cin >> a >> b >> k;
    ll res_a = a-k;
    if(res_a < 0)b = b + res_a;
    cout << max(res_a,0LL) << " " << max(b,0LL) << endl;
}