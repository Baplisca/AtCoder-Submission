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
    set<ll> s;
    for(int i=0;i<n;i++){
        int j;cin >> j;
        s.insert(j);
    }
    if(s.size() == n)cout << "YES" << endl;
    else cout << "NO" << endl;
}
    