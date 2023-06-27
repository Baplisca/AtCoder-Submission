#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[i][j] > a[i][j + 1])
                mp[{a[i][j + 1], a[i][j]}]++;
            else
                mp[{a[i][j], a[i][j + 1]}]++;
        }
    }
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n + 1; j++)
        {
            if (mp[{i, j}] == 0)
                res++;
        }
    }
    cout << res << endl;
}