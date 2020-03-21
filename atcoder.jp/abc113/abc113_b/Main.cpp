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
    int n,t,a; cin >> n >> t >> a;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    double min = INF;
    int min_id = 0;
    for(int i=0;i<n;i++){
        double di = t - h[i]*0.006;
        if(min > abs(a - di)){
            min = abs(a - di);
            min_id = i+1;
        }
    }
    cout << min_id << endl;
}
    