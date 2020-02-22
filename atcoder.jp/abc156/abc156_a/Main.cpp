#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int N,R;
    cin >> N >> R;
    if(N >= 10)
        cout << R << endl;
    else
        cout << R + (100*(10-N)) << endl;
}
