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
    
    bool is_ap = true;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        if(a%2)continue;
        if(a%3 && a%5){
            is_ap = false;
            break;
        }
    }
    cout << (is_ap? "APPROVED":"DENIED")<< endl;
}
    