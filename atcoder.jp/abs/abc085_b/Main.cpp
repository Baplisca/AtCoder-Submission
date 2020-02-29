#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> a;
    int num;
    for(int i=0;i<n;i++){
        cin >> num;
        a.insert(num);
    }
    cout << a.size() << endl;
}