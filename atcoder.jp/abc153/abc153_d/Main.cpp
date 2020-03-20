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

ll count_attack(ll h){
    if(h <= 1) return 1;
    return (2*count_attack((h)/2) + 1);
}
int main()
{
    ll h; cin>> h;
    cout << count_attack(h) << endl;
}
    