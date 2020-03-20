#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;

int main() {
    int n;cin >> n;
    vector<int> w(n);
    for(int i=0;i<n;i++)cin >> w[i];

    ll count = INF;
    for(int i=1;i<=n;i++){
        ll a = 0,b=0;
        for(int j=0;j<n;j++){
            if(j+1 <= i) a+=w[j];
            else b+=w[j];
        }
        count = min(count, abs(a-b));
    }
    cout << count << endl;
}