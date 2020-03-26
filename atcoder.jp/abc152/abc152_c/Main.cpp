#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int n; cin >> n;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    int mi = p[0];
    int res = 1;
    for(int i=1;i<n;i++){
        mi = min(mi,p[i]);
        if(mi == p[i]) res++;
    }
    cout << res << endl;
}
    