#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(), (v).end()
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int n,k; cin >> n >> k;
    vector<int> h(n);
    for(int i=0;i<n;i++)cin >> h[i];
    sort(all(h));
    int res = lower_bound(all(h),k) - h.begin();
    cout << n-res << endl;
}