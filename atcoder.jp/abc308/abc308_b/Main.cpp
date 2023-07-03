#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    vector<string> d(m);
    vector<int> p(m + 1);
    map<string, int> mp;
    for (int i = 0; i < m; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i < m + 1; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < m; i++)
    {
        mp[d[i]] = p[i + 1];
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[s[i]] == 0)
        {
            res += p[0];
        }
        else
        {
            res += mp[s[i]];
        }
    }
    cout << res << endl;
}
