#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, d;
    cin >> n >> d;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int res = 0;
    for (int i = 0; i < d; i++)
    {
        for (int j = i; j < d; j++)
        {
            bool is_judge = true;
            for (int k = 0; k < n; k++)
            {
                if (s[k][j] == 'x')
                {
                    is_judge = false;
                }
            }
            if (!is_judge)
            {
                break;
            }
            res = max(res, j - i + 1);
        }
    }
    cout << res << endl;
}
