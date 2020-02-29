#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int y;
    cin >> y;
    int i,j;
    bool is_check = false;
    for (i = 0; i <= n; i++)
    {
        for(j=0;j<=n-i;j++){
            if(10000*i+5000*j+1000*(n-i-j) == y){
                cout << i << " " << j << " " << n-i-j<<endl;
                i = n+1;
                is_check = true;
            }
        }
    }
    if(!is_check)
        cout << "-1 -1 -1"<<endl;
}