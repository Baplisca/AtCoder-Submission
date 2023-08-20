#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, t;
    cin >> n >> t;
    vector<int> c(n), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    int res = -1, ma = -1;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == t && r[i] > ma)
        {
            ma = r[i];
            res = i + 1;
        }
    }
    if (res != -1)
    {
        cout << res << endl;
        return 0;
    }
    res = 1, ma = r[0];
    for (int i = 1; i < n; i++)
    {
        if (c[i] == c[0] && r[i] > ma)
        {
            ma = r[i];
            res = i + 1;
        }
    }
    cout << res << endl;
}
