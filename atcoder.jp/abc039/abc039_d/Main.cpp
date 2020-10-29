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
    vs s(h);
    rep(i,h)cin >> s[i];
    vvb pre_black(h,vb(w));

    rep(i,h){
        rep(j,w){
            if(s[i][j] == '.')continue;
            bool is_black = true;
            rep(k,8){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
                if(s[nx][ny] == '.')is_black = false;
            }
            if(is_black)pre_black[i][j] = true;
        }
    }

    vvc nv(h,vc(w));
    rep(i,h){
        rep(j,w){
            if(pre_black[i][j])nv[i][j] = '#';
            else nv[i][j] = '.';
        }
    }

    vvc ns(h,vc(w,'.'));
    //nvを膨張した時に、nsを作成
    rep(i,h)rep(j,w){
        if(nv[i][j] == '.')continue;
        ns[i][j] = '#';
        rep(k,8){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
            ns[nx][ny] = '#';
        }
    }

    //nsとsの矛盾がないか
    rep(i,h)rep(j,w)if(ns[i][j] != s[i][j]){
        out("impossible");
        return 0;
    }
    out("possible");
    rep(i,h){
        rep(j,w){
            cout << nv[i][j];
        }
        cout << endl;
    }
}   
