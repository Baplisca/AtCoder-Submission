#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    
    
    cin >> N;
    
    vector<int> vec(N);
    for(int i=0;i<N;i++)
        cin >> vec.at(i);
        
    int ave =  accumulate(vec.begin(), vec.end(), 0) / N;
    for(int i=0;i<N;i++)
        cout << abs(vec.at(i) - ave) << endl;
        
        
}
