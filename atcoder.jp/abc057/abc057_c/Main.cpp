#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

int calc_digit(ll x){
    int res = 0;
    while(x > 0){
        x /= 10;
        res++;
    }
    return res;
}
int main()
{
    ll n; cin >> n;
    int res = calc_digit(n);
    
    //cout << res << endl;
    for(ll i=2;i*i <= n;i++){
        if(n % i == 0){
            res = min(res,calc_digit(n/i));
        }
    }
    cout << res << endl;
}
