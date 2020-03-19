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
    int n; cin >> n;
    map<string,int> mp;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        mp[s]++;
    }
    
    int i_max = 0;
    for(auto itr = mp.begin();itr != mp.end();itr++){
        i_max = max(itr->second,i_max);
        
    }
    for(auto itr = mp.begin();itr != mp.end();itr++){
        if(itr->second == i_max)cout << itr->first <<endl;
    }
}
    