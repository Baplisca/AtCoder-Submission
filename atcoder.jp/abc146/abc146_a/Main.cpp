#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    string week[] = {"SUN","MON","TUE","WED","THU","FRI","SAT" };
    string s; cin >> s;
    int a;
    for(int i=0;i<7;i++){
        if(s == week[i])a=i;
    }
    if(s=="SUN") cout << 7 << endl;
    else cout << 7-a << endl;
}