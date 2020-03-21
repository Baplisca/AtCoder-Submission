#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;

int main() {
    int n; cin >> n;
    int count = 0;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        while(a % 2 == 0|| a % 3 == 2){
            count++;
            a--;
        }
    }
    cout << count << endl;
}