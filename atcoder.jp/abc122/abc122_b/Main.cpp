#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    map<char,int> mp{{'A',1},{'T',1},{'G',1},{'C',1}};
    string a; cin >> a;
    int res = 0;
    for(int i=0;i<a.size();i++){
        int sum = 0;
        int j=i;
        while(mp[a[j]] && j<a.size()){
            sum++;j++;
        }
        res = max(sum,res);
    }
    cout << res << endl;
}
    