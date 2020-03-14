#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

int main() {
    string s; cin >> s;
    reverse(s.begin(),s.end());
    ll odd = 0, even = 0;
    for(int i=0;i<s.size();i+=2)odd += s[i] - '0';
    for(int i=1;i<s.size();i+=2)even += s[i] - '0';
    cout << even << " " << odd << endl;
}   
