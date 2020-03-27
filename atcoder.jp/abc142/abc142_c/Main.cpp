#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main()
{   
    int n; cin >> n;
    vector<pair<int,int> > a(n);
    rep(i,n){
        int j; cin >> j;
        a[i]=make_pair(j,i+1);
    }
    sort(all(a));
    rep(i,n){
        if(i!=0) cout <<" ";
        cout << a[i].second;
    }
    cout << endl;
}