#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

int main() {
    vector<int> n(5);
   for(int i=0;i<5;i++)cin >> n[i];
   vector<int> total;

   for(int i=0;i<5;i++){
       for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++){
                int ans = n[i] + n[j] + n[k];
                if(count(total.begin(), total.end(), ans) == 0)total.push_back(ans);
            }   
        }
   }
   sort(total.begin(),total.end(),greater<int>());
   cout << total[2] << endl;
}   

