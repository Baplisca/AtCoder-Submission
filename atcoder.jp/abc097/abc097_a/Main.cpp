#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int a,b,c,d;cin >>a>>b>>c>>d;
    if(abs(a-c) <= d || (abs(a-b) <= d && abs(b-c) <= d))
        cout << "Yes" << endl;
    else cout << "No" << endl;
}
