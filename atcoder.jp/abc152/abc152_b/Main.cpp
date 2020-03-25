#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int a,b; cin >> a >> b;
    string sa="",sb="";
    for(int i=0;i<b;i++)sa+=to_string(a);
    for(int i=0;i<a;i++)sb+=to_string(b);
    cout << (sa<sb?sa:sb) << endl;
}
    