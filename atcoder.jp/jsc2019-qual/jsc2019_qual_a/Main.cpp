#include <bits/stdc++.h>
using namespace std;
int main(void){
    int m,d; cin >> m >> d;
    int res = 0;
    for(int i=4;i<=m;i++){
        for(int j= 22;j<=d;j++){
            int k=j/10;
            int x=j%10;
            if(i == x*k && x>=2 && k>=2)res++;
        }
    }
    cout << res << endl;
}
