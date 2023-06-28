#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<int> b(n + 1);
    vector<pair<int, int>> p;
    for (int i = 0; i < 3 * n; i++)
    {
        int a;
        cin >> a;
        b[a]++;
        if (b[a] == 2)
        {
            cout << a << " ";
        }
    }
    cout << endl;
}