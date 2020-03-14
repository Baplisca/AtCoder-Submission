#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

int main() {
    ll H,W; cin >> H >> W;
    if(H==1 || W == 1)cout << "1" << endl;
    else cout << (H*W+1)/2 << endl;
}   
