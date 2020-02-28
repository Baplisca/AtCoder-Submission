#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }
    int count = 0;
    bool is_loop = false;
    for(int i=0;i<n;i++){
        if(a.at(i)%2)is_loop=true;
    }
    while (!is_loop)
    {
        for(int i=0;i<n;i++){
            if((a.at(i)/=2) % 2 == 1)is_loop=true;
        }
        count++;
    }
    cout << count << endl;
}