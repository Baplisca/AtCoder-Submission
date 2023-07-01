#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
        if (a[i] < a[i + 1])
        {
            while (a[i] + 1 < a[i + 1])
            {
                cout << ++a[i] << " ";
            }
        }
        else
        {
            while (a[i] - 1 > a[i + 1])
            {
                cout << --a[i] << " ";
            }
        }
    }
    cout << a[n - 1] << " ";
    cout << endl;
}