#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> t(n),x(n),y(n);
    for(int i=0;i<n;i++){
        cin >> t.at(i) >> x.at(i) >> y.at(i);
    }
    bool is_able = true;
    int dist = abs(x.at(0))+abs(y.at(0));
    int diff = t.at(0) - dist;
    if(diff >= 0 && diff % 2 == 0);
    else is_able = false;
    for(int i=0;i<n-1;i++){
        int dist = abs(x.at(i+1)-x.at(i))+abs(y.at(i+1)-y.at(i));
        int diff = t.at(i+1)-t.at(i) - dist;
        if(diff >= 0 && diff % 2 == 0);
        else is_able = false;
    }
    if(is_able)cout << "Yes"<<endl;
    else cout <<"No" << endl;
}