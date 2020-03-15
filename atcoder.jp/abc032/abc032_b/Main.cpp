#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

int main() {
    string s;
    int k; cin >> s >> k;
    int n = s.size();
    map<string,int> mp;
    if(n < k){
        cout << "0" << endl;
        return 0;
    }
    int res = 0;
    for(int i=0;i+k-1<s.size();i++){
        string s1 = s.substr(i,k);
        if(mp[s1] == 0){
            mp[s1]++;
            res++;
        }
    }
    cout << res << endl;
}   

