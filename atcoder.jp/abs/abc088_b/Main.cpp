#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a.at(i);
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int sum1 = 0,sum2=0;
    for (int i = 0; i < n; i+=2)
    {
        sum1+=a.at(i);
    }
    for (int i = 1; i < n; i+=2)
    {
        sum2 +=a.at(i);
    }
    cout<<sum1-sum2<<endl;
}