#include <bits/stdc++.h>
using namespace std;

int main(void){
   int n,y;
   cin >> n >> y;
   int res_i = -1,res_j=-1,res_k=-1;
   for(int i=0;i<=n;i++){
       for(int j=0;j<=n-i;j++){
           int money = 10000*i+5000*j+1000*(n-i-j);
           if(money == y){
               res_i = i;
               res_j = j;
               res_k = n-i-j;
           }
       }
   }
   cout << res_i << " " << res_j << " " << res_k << endl;
}
