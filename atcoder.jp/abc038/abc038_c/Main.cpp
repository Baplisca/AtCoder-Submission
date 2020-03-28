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

int facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

int main()
{   
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    long long res = 0;
    int right = 1;
    rep(left,n){
        while(right < n && ( right == left || a[right -1] < a[right])){
            right++;
        }
        res += right - left;
        if(right == left) right++;
    }
    cout << res << endl;
    
}
