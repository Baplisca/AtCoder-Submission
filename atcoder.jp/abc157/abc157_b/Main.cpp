#include <bits/stdc++.h>
using namespace std;

int main(void){
   vector<vector<string> > a(3,vector<string>(3));
   for(int i=0;i<3;i++){
       for (int j = 0; j< 3; j++)
       {
           cin >> a[i][j];
       }  
   }
   int n;
   cin >> n;
   vector<string> b(n);
   for(int i=0;i<n;i++){
       cin >> b[i];
   }
    vector<bool> c(9,false);
    for(int i=0;i<3;i++){
       for (int j = 0; j< 3; j++)
       {
           for(int k=0;k<n;k++){
               if (b[k] == a[i][j]) {
                   c[3*i+j] = true;
               }
           }
       }  
   }
   if(c[0] && c[1] && c[2] || c[3] && c[4] && c[5] || c[6] && c[7] && c[8] || 
   c[0] && c[3] && c[6] || c[1] && c[4] && c[7] || c[2] && c[5] && c[8] ||
   c[0] && c[4] && c[8] || c[2] && c[4] && c[6]) cout << "Yes" << endl;
   else cout << "No" << endl;
}
