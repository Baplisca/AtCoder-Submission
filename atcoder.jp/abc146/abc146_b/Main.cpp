#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int n; string s;
    cin >> n >> s;
    for(int i=0;i<s.size();i++){
        int c = 'Z';
        if(s[i]+n > c)
        printf("%c",s[i]+n-26);
        else 
        printf("%c",s[i]+n);
    }
    cout << endl;
}