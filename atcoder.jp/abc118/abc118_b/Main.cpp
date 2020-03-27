#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int n,m; cin >> n >> m;
    map<int,int> a;
    rep(i,n){
        int k; cin >> k;
        rep(j,k){
            int b; cin >> b;
            a[b]++;
        }
    }
    int ans = 0;
    for(auto res:a){
        if(res.second == n)ans++;
    }
    cout << ans << endl;
}