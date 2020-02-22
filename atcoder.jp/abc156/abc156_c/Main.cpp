#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    vector<int> X(N);
    for(int i=0;i<N;i++)
       cin >> X.at(i);
    int min = N*99*99;
    for(int i=1;i<=100;i++){
         int dist = 0;
        for(int j=0;j<N;j++){
            dist += (X.at(j) - i)*(X.at(j) - i);
        }
        if(dist < min){
            min = dist;
        }
    }
    cout << min << endl;
}
