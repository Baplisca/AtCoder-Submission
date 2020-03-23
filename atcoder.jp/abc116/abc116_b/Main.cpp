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

int f(int n){
    if(n%2)return 3*n+1;
    else return n/2;
}
int main()
{   
    int s; cin >> s;
    vector<ll> n(1000001,0);
    n[0] = s;
    map<int,int> m;
    m[s]++;
    int res;
    for(int i=1;i<= 1000000;i++){
        n[i] = f(n[i-1]);
        m[n[i]]++;
        if(m[n[i]] >= 2){
            res = i+1;
            break;
        }
    }
    cout << res << endl;
}
    