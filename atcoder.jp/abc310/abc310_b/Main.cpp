#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n), c(n);
    vector<vector<int>> f(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        cin >> c[i];
        for (int j = 0; j < c[i]; j++)
        {
            int F;
            cin >> F;
            f[i][--F]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            bool is_match = true;
            bool is_overwelm = false;
            for (int k = 0; k < m; k++)
            {
                if (f[i][k] && !f[j][k])
                    is_match = false;
                if (f[j][k] && !f[i][k])
                    is_overwelm = true;
            }
            // jが上位互換か
            if (is_match && p[i] >= p[j] && (is_overwelm || p[i] > p[j]))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
