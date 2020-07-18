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
    int n,k; cin >> n >> k;
    vl x(n),y(n);
    rep(i,n)cin>>x[i]>>y[i];
    ll res = LLONG_MAX;
    rep(i,n){
        for(int ii = i+1;ii<n;ii++){
            rep(j,n){
                for(int jj = j+1;jj<n;jj++){
                    ll ma_x = max(x[i],x[ii]);
                    ll ma_y = max(y[j],y[jj]);
                    ll mi_x = min(x[i],x[ii]);
                    ll mi_y = min(y[j],y[jj]);
                    ll area = (ma_x - mi_x)*(ma_y - mi_y);
            
                    //4点に囲まれた点が何個あるかカウント
                    ll cnt = 0;
                    rep(idx,n){
                        //x座標
                        if(x[idx] < mi_x || x[idx] > ma_x)continue;
                        //y
                        if(y[idx] < mi_y || y[idx] > ma_y)continue;
                        cnt++;
                    }
                    if(cnt >= k)res = min(area,res);
                }
            }
        }
    }
    out(res);
}