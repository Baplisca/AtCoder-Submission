#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
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

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    UnionFind(int N) : par(N),siz(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++){
             par[i] = i;
             siz[i] = 1;
        }
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        // merge technique（小を大にくっつける）
        if (siz[rx] < siz[ry]) swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    ll size(ll x){
        return siz[root(x)];
    }
};

signed main()
{   
    gearup;
    ll h,w,k; cin >> h >> w >> k;
    vs s(h);
    rep(i,h)cin>>s[i];
    ll res = L_INF;
    rep(i,1<<(h-1)){
        int row = 0;
        vl trans(h);
        rep(j,h){
            trans[j] = row;
            if((i >> j) & 1)row++;
        }
        row++;
        vvl sum(row,vl(w));
        rep(j,h)rep(k,w)sum[trans[j]][k] += s[j][k] - '0';

        //Greedyに求める
        ll num = row-1; //分割数
        vector<int> now(row);

        auto add = [&](int j) {
            rep(i,row) now[i] += sum[i][j];
            rep(i,row) if (now[i] > k) return false;
            return true;
        };
        rep(j,w) {
            if (!add(j)) {
                num++;
                now = vector<int>(row);
                if (!add(j)) {
                    num = INF;
                    break;
                }
            }
        }
        res = min(res, num);
    }
    out(res);
}
