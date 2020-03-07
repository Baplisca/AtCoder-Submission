#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll a,b;
    cin >> a >> b;
    bool is_res = false;
    for(int i=1;i<= 1000;i++){
        if((int)(i*0.08) == a && (int)(i*0.1) == b){
            cout << i << endl;
            is_res = true;
            break;
        }
    }
    if(!is_res)cout << "-1" << endl;
}
