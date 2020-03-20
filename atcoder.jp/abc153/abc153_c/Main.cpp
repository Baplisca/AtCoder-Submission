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
    int n,k; cin >> n >> k;
    vector<ll> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    sort(h.begin(),h.end());
    ll count =0;
    for(int i=0;i<n-k;i++){
        count += h[i];
    }
    cout << count << endl;
}
    