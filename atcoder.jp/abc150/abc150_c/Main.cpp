#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int n; cin >> n;
    vector<int> p(n),q(n);
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++) cin >> q[i];
    vector<int> a;
    for(int i=0;i<n;i++)a.push_back(i+1);
    int coun = 0,x,y;
    do{
        if(equal(a.begin(), a.end(), p.begin())) 
            x = coun;
        if(equal(a.begin(), a.end(), q.begin()))
            y = coun;
        coun++;
    }while(next_permutation(a.begin(),a.end()));
    cout << abs(x-y) << endl;
}