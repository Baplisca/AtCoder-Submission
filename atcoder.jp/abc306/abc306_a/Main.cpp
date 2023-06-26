#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size() * 2; i++)
    {
        int j = i / 2;
        cout << s[j];
    }
    cout << endl;
}