#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<bool> loses(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        loses[--b] = true;
    }
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (!loses[i])
            res.push_back(i);
    }
    if (res.size() == 1)
        cout << res[0] + 1 << endl;
    else
        cout << -1 << endl;
}
