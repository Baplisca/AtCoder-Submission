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
    vector<vector<char> > s(H+2,vector<char>(W+2));
    ll wal_num = 0;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            char c; cin >> c;
            s[i][j] = c;
            if(c == '#')wal_num++;
        }
    }
   
    int dy[4] = {1,0,-1,0};
    int dx[4] = {0,1,0,-1};
    vector<vector<ll> > dist(H+2,vector<ll>(W+2,MOD));
    dist[1][1] = 1;
    queue<pair<int,int>> Q;
    Q.push(make_pair(1,1));

    while(!Q.empty()){
        int cx = Q.front().first,cy = Q.front().second;
        Q.pop();
        for(int i=0;i<4;i++){
            int ex = cx + dx[i],ey = cy + dy[i];
            //行先が壁、探索済ならやめる
            if(s[ex][ey] != '.' || dist[ex][ey] != MOD)continue;
            dist[ex][ey] = dist[cx][cy] + 1;
            Q.push(make_pair(ex, ey));
        }
    }
    if(dist[H][W] == MOD)cout << -1 << endl;
    else cout << (H*W - wal_num - dist[H][W]) << endl;
}
    