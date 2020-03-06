#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
   int n,m;
   cin >> n >> m;
   vector<vector<int> > s(m,vector<int>(n));
   vector<int> k(m),p(m);
   for(int i=0;i<m;i++){
       cin>>k[i];
       for(int j=0;j<k[i];j++){
           cin >> s[i][j];
       }
   }
   for(int i=0;i<m;i++) cin >> p[i];

   int count = 0;
   for (int bit = 0; bit < (1<<n); ++bit) {
       bool is_enable = true;
       for(int i=0;i<m;i++){
        int sum = 0;
            for (int j = 0; j < k[i];j++) {
                if (bit & (1 << s[i][j]-1)) sum++;
            }
        if(sum % 2 != p[i])is_enable = false;
       }
       if(is_enable)count++;
    }
    cout << count << endl;
}
