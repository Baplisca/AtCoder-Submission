#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int n,k,m; cin >> n >> k >> m;
    vector<int> a(n-1);
    for(int i=0;i<n-1;i++)cin >> a[i];
    int su = accumulate(a.begin(),a.end(),0);
    for(int i=0;i<=k;i++){
        if((su+i) >= n*m){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
    