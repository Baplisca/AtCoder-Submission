#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i < n; ++i)
#define exrep(i, a, b) for (ll i = a; i < b; i++)
#define out(x) cout << x << endl

int main(void){
    int q; 
    cin >> q; 
    stack<string> pre;
    std::vector<string> S;
    rep(i,q){
        string s; 
        cin >> s;
        if(s == "READ")S.push_back(pre.top()),pre.pop();
        else pre.push(s);
    }
    rep(i,S.size())out(S[i]);
}
