#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    int count = 0;
    for(int i=1;i<=n;i++){
        int sum = 0;
        int x = i;
        while(x > 0){
            sum += x% 10;
            x/=10;
        }
        if(sum >= a && sum <= b)count+=i;
    }
    cout << count<<endl;
}