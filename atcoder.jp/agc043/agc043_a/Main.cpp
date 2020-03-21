#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int H,W; cin >> H >> W;
    char s[H+2][W+2];
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> s[i][j];
        }
    }
    vector<vector<ll> > dist(H+2,vector<ll>(W+2,MOD));
    if(s[1][1] == '#')dist[1][1] = 1;
    else dist[1][1] = 0;
    for(int i=1;i<= H;i++){
        for(int j=1;j<=W;j++){
            //下右に動く
            int dy[4] = {1,0};
            int dx[4] = {0,1};
            for (int k = 0; k < 2; k++) {
                int ex = i + dx[k], ey = j + dy[k];
        
                if (s[ex][ey] == '.' || s[ex][ey] == '#'){
                    if(s[ex][ey] == '.')
                        chmin(dist[ex][ey],dist[i][j]);
                    else if(s[ex][ey] == '#'){
                        if(s[i][j] == '#')
                            chmin(dist[ex][ey],dist[i][j]);
                        else
                            chmin(dist[ex][ey],dist[i][j] + 1);
                    }
                }
            }
        }
    }
    cout << dist[H][W] << endl;
}
    