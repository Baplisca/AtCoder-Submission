#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int n;ll x; cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) if(a[i] == 0) {
        cout << n << endl;
        return 0;
    }
        ll sum = 1;
        int res = 0;
        int right = 0;
        rep(left,n){
            while(right < n && sum*a[right]<= x){
                sum *= a[right];
                right++;
            }
            res = max(right - left,res);
            if(right == left) right++;
            else sum /= a[left];
        }
        cout << res << endl;
    
}
