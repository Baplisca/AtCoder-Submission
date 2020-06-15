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

signed main()
{   
    gearup;
    int n,q; cin >> n >> q;
    vl a(n),b(n);
    vector<multiset<int> > ga(200010); //幼稚園のレート格納
    multiset<int> max_ga; //各幼稚園の最大値

    auto get_max = [&](int i){ //iの幼稚園について最大値を返す
        if(ga[i].size() == 0)return -1;
        return *ga[i].rbegin();
    };
    auto add_ga = [&](int i){ //iの幼稚園について最大値を格納
        int x = get_max(i);
        if(x == -1)return;
        max_ga.insert(x);
    };
    auto del_ga = [&](int i){ 
        int x = get_max(i);
        if(x == -1)return;
        max_ga.erase(max_ga.find(x));
    };
    auto add = [&](int i, int j){
        del_ga(i);
        ga[i].insert(j);
        add_ga(i);
    };
    auto del = [&](int i,int j){
        del_ga(i);
        ga[i].erase(ga[i].find(j));
        add_ga(i);
    };
    rep(i,n){
        cin >> a[i] >> b[i]; //b[i]に所属
        add(b[i], a[i]); //a[i]のレートをいれる
    }

    rep(i,q){
        int c,d; cin >> c >> d; //幼児cを幼稚園dへ移動
        c--;
        del(b[c],a[c]); //元の幼稚園から削除手続き
        b[c] = d;
        add(b[c],a[c]); //先の幼稚園へ入園手続き
        int num = *max_ga.begin();
        out(num);
    }
}
