#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

double adjust_n(int n,int m){
    return (n + m/60.0);
}
int main() {
    int n,m; cin >> n >> m;
    n %= 12;
    double d_n = adjust_n(n,m);
    double angle = abs((m - d_n*5.0) * 6.0);
    printf("%.4f",min(angle,360-angle));
    cout << endl;
}   

