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

const int max_n = 8100;
bool pos_x[max_n][max_n*2];
bool pos_y[max_n][max_n*2];
signed main()
{
    gearup;
    string s; cin >> s;
    ll x,y; cin >> x >> y;

    vl dist;
    ll dif = 0;
    rep(i,s.size()){
        if(s[i] == 'T'){
            if(dif!=0)dist.push_back(dif);
            dist.push_back(0);
            dif = 0;
        }
        else{
            dif++;
            if(i == s.size() -1)dist.push_back(dif);
        }
    }
    ll dif_x = 0;
    if(dist[0] != 0){
        dif_x = dist[0];
        dist.erase(dist.begin());
    }
    pos_x[0][max_n + dif_x] = true;
    pos_y[0][max_n] = true;
    int idx_x = 0,idx_y = 0;
    bool is_dir_x = true;

    int m = dist.size();
    rep(i,m){
        if(dist[i] == 0)is_dir_x = !is_dir_x;
        else if(is_dir_x){
            idx_x++;
            rep(j,max_n*2){
                if(pos_x[idx_x-1][j]){
                    pos_x[idx_x][j+dist[i]] = true;
                    pos_x[idx_x][j-dist[i]]=true;
                }
            }
        }
        else{
            idx_y++;
            rep(j,max_n*2){
                if(pos_y[idx_y-1][j]){
                    pos_y[idx_y][j+dist[i]] = true;
                    pos_y[idx_y][j-dist[i]] = true;
                }
            }
        }
    }
    if(pos_x[idx_x][max_n + x] && pos_y[idx_y][max_n + y])out("Yes");
    else out("No");
}