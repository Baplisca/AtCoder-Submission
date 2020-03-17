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
    int n; cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    vector<ll> a(n+1,INF);
    a[0] = 0;
    for(int i=1;i<n;i++){
        chmin(a[i],a[i-1]+abs(h[i]-h[i-1]));
        if(i!=1) chmin(a[i],a[i-2]+abs(h[i] -h[i-2]));
    }
    cout << a[n-1] << endl;
}