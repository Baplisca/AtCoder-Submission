#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

int main()
{
    int n; cin >> n;
    for(int i=2;i<= sqrt(n);i++){
        if(n % i == 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
