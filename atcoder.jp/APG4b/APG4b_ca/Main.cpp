#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int N;
    vector<tuple<int,int>> p;
    int a,b;
    
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> a >> b;
        p.push_back(make_tuple(b,a));
    }
    
    sort(p.begin(),p.end());
    //出力
    for (tuple<int, int> t : p) {
    int x, y;
    tie(x, y) = t;
    cout << y << " " << x << endl;
  }
}
