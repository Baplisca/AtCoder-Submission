#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int N,K;
    cin >> N >> K;
    if (N < K)
     cout << 1 << endl;
    else{
        int i;
        i = N/K;
        int count = 2;
        while(i >= K){
            count++;
            i = i/K;
        }
        cout << count << endl;
    }
}
