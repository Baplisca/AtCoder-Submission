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

signed main()
{
    gearup;
    int n; cin >> n;
    vl d(n);
    vl num(13);
    num[0] = 1; //すでに0時にはいる
    rep(i,n){
        cin>>d[i]; //0~12
        num[d[i]]++;
    }
    rep(i,13){
        if(i == 0 || i == 12){
            if(num[i] >= 2){
                out(0);
                return 0;
            }
        }
        else{
            if(num[i] >= 3){
                out(0);
                return 0;
            }
        }
    }

    //numが1個の場合をbit全探索
    ll res = 0;
    rep(i,1<<12){
        vl table(24);
        table[0] = 1;
        table[12] = num[12];
        rep1(j,12){ //1~11まで
            if(num[j] == 2)table[24-j] = table[j] = 1;
            else if(num[j] == 1){
                if( (i >> j) & 1) table[j] = 1;
                else table[24-j] = 1;
            }
        }

        ll mi = L_INF;
        rep(ii,24){
            for(int jj = ii+1;jj<24;jj++){
                if(table[ii] && table[jj]){
                    mi = min(mi,abs(jj-ii));
                    mi = min(mi,24-abs(jj-ii));
                }
            }
        }
        res = max(res,mi);
    }
    out(res);
}