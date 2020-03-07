#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll n,a,b;
    cin >> n >> a >> b;
    ll sub_a = (n/(a+b))*a;
    ll sub_b = (n/(a+b))*b;
    ll dub = n - (sub_a+sub_b);
    if(dub >= a)cout << sub_a+a << endl;
    else cout << sub_a + dub % a << endl;
}
