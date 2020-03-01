#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int res1,res2,res3;
    res1 = a*x+b*y;
    int mi = min(x,y);
    res2 = c*2*mi+(x-mi)*a+(y-mi)*b;
    int ma = max(x,y);
    res3 = c*2*ma;
    cout << min(res1,min(res2,res3)) << endl;
}