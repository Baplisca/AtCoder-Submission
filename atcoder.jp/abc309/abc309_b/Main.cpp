#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ii, jj;
            if (i == 0)
            {
                if (j == n - 1)
                {
                    ii = 1, jj = n - 1;
                }
                else
                {
                    ii = i, jj = j + 1;
                }
            }
            else if (i == n - 1)
            {
                if (j == 0)
                {
                    ii = n - 2;
                    if (ii < 0)
                    {
                        ii += n;
                    }
                    jj = 0;
                }
                else
                {
                    ii = i, jj = j - 1;
                }
            }
            else if (j == 0)
            {
                if (i == 0)
                {
                    ii = 0, jj = 1;
                }
                else
                {
                    ii = i - 1, jj = 0;
                }
            }
            else if (j == n - 1)
            {
                if (i == n - 1)
                {
                    jj = n - 2;
                    if (jj < 0)
                    {
                        jj += n;
                    }
                    ii = i;
                }
                else
                {
                    ii = i + 1, jj = j;
                }
            }
            else
            {
                ii = i, jj = j;
            }
            b[ii][jj] = a[i][j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << b[i][j];
        }
        cout << endl;
    }
}
