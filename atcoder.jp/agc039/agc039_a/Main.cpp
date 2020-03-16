#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

ll count_dup(string s){
    ll a = 0;
    for (int i = 0,j=0; i < s.size(); i=j)
    {
        while (j < s.size() && s[i] == s[j])j++;
        a += (j-i)/2;
    }
    return a;
}

int main()
{
    string s;
    ll k;
    cin >> s >> k;

    //sが同じ文字かチェック
    bool is_same = true;
    for (int i = 1; i < s.size(); i++) if (s[0] != s[i]) is_same = false;
    if (is_same)
    {
        cout << (s.size() * k) / 2 << endl;
        return 0;
    }

    //初項を求める
    ll a = count_dup(s);
    //cout << a << endl;
    ll aa = count_dup(s+s);
    //cout << aa << endl;
    ll d = aa - a;
    cout << a + (k - 1) * d << endl;
}
