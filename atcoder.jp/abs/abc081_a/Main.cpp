#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count =0;
    for (int i = 0; i < s.size(); i++)
    {
        /* code */
        if(s.at(i) == '1')count++;
    }
    cout << count << endl;
    return 0;
}