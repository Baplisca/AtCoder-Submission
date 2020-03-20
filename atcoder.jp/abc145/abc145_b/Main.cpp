#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;cin >> n >> s;
    bool is_same = true;
    if(n == 1 || n%2) is_same = false;
    else{
        for(int i=0;i<s.size()/2;i++){
        if(s[i] != s[i+s.size()/2])is_same = false;
        }
    }
    cout << (is_same?"Yes":"No") << endl;
}