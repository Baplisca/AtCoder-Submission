#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<bool> > vvb;
typedef vector<vector<double> > vvd;
typedef vector<vector<string> > vvs;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//以降 cin の入力元が 'input.txt' になる
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());

signed main() {
    gearup;
    ll h,w; cin >> h >> w;
    ll c1,c2; cin >> c1 >> c2;c1--;c2--;
    ll d1,d2; cin >> d1 >> d2;d1--;d2--;
    vs s(h);
    rep(i,h)cin>>s[i];
    vvb visited(h,vb(w));
    deque<pair<int,int> > que;
    vvl cnt(h,vl(w,-1));
    que.push_front({c1,c2});
    cnt[c1][c2] = 0;
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop_front();
        if(visited[x][y])continue;
        visited[x][y] = true;
        for(int i=0;i<8;i+=2){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
            if(s[nx][ny] == '#')continue;
            if(cnt[nx][ny] == -1){
                cnt[nx][ny] = cnt[x][y];
                que.push_front({nx,ny});
            }
            else{
                if(chmin(cnt[nx][ny],cnt[x][y]))que.push_front({nx,ny});
            } 
            
        }
        for(int i=-2;i<3;i++){
            for(int j=-2;j<3;j++){
                if(i == 0 && j == 0)continue;
                int nx = x + i;
                int ny = y + j;
                if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
                if(s[nx][ny] == '#')continue;
                if(cnt[nx][ny] == -1){
                cnt[nx][ny] = cnt[x][y] + 1;
                que.push_back({nx,ny});
                }
                else{
                    if(chmin(cnt[nx][ny],cnt[x][y] + 1))que.push_back({nx,ny});
                } 
            }
        }
    }
    out(cnt[d1][d2]);
    //rep(i,h)debug(cnt[i]);
}   
