#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<pair<string, int>> p;
    int min_idx = -1, mi = 1000101000;
    for (int i = 0; i < n; i++)
    {
        string s;
        int a;
        cin >> s >> a;
        p.push_back({s, a});
        if (a < mi)
        {
            mi = a;
            min_idx = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << p[(min_idx + i) % n].first << endl;
    }
}
