#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;

double dist(int x,int x1,int y,int y1){
    double d=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
    return d;

}
int main() {
    int xa,ya,xb,yb,t,v;
    cin >> xa >> ya >> xb >> yb >> t >> v;
    int n; cin >> n;
    vector<int> x(n),y(n);
    for(int i=0;i<n;i++) cin >> x[i] >> y[i];
    bool is_res = false;
    for(int i=0;i<n;i++){
        double dis = 0.0;
        dis += dist(xa,x[i],ya,y[i]);
        dis += dist(x[i],xb,y[i],yb);
        if(dis <= t*v*1.0)is_res = true;
    }
    cout << (is_res?"YES":"NO") << endl;
}