#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

int main() {
    char a[100];
    int n; cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    double count = 0.0;
    for(int i=0;i<n;i++){
        if(a[i] == 'A')count+=4;
        else if(a[i] == 'B')count+=3;
        else if(a[i] == 'C')count+=2;
        else if(a[i] == 'D')count++;
    }
    printf("%.10f",count/n);
}   

