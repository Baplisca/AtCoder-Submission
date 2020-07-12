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
    ll n;
    string x; cin >> n >> x;
    ll num = 0;
    rep(i,n)if(x[i] == '1')num++;
    if(num==0){
        rep(i,n){
            out(1);
        }
        return 0;
    }
    vl memo(200001,0);
    rep1(i,n){
        ll bit = 0;
        rep(j,30){
            if(1 & (i >> j))bit++;
        }
        memo[i] = memo[i % bit] + 1;
    }
    //mod num+1の値
    vl pmod(n);
    ll pnum = 1;
    rep(i,n){
        pmod[n-i-1] = pnum;
        pnum = pnum * 2 % (num+1);
    }
    //mod num-1の値
    vl mmod(n);
    ll nnum = 1;
    rep(i,n){
        if(num-1 > 0){
            mmod[n-i-1] = nnum;
            nnum = nnum * 2 % (num-1);
        }
    }
    ll pres = 0, mres = 0;
    rep(i,n){
        if(x[i] == '1'){
            pres += pmod[i];
            mres += mmod[i];
        }
    }

    //いずれかのビットが立っている
    rep(i,n){
        ll n_num = num;
        if(x[i] == '0')n_num++;
        else n_num--;
        //立っているビット数はn_num
        if(n_num == num+1){
            ll sum = pres;
            sum += pmod[i];
            sum %= n_num;
            ll cnt = 1;
            cnt += memo[sum];
            out(cnt);
        }
        else{
            if(n_num == 0)out(0);
            else{
                ll sum = mres;
                sum -= mmod[i];
                while(sum <= 0)sum += n_num;
                sum %= n_num;
                ll cnt = 1;
                cnt += memo[sum];
                out(cnt);
            }
        }
    }
}