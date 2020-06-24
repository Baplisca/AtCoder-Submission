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
    ll n,k,c; cin >> n >> k >> c;
    string s; cin >> s;
    vl left(n,-1),right(n,-1);
    ll pre_day = -L_INF;
    ll cnt = 0;
    rep(i,n){
        if(s[i] == 'o'){
            if(i - pre_day > c){
                left[i] = cnt;
                pre_day = i;
                //out(i);
                cnt++;
                if(cnt >= k)break;
            }
        }
    }
    pre_day = L_INF;
    cnt = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i] == 'o'){
            if(pre_day - i > c){
                right[i] = cnt;
                pre_day = i;
                //out(i);
                cnt++;
                if(cnt >= k)break;
            }
        }
    }

    rep(i,n)if(right[i] >= 0)right[i] = k-right[i]-1; //leftに合わせる
    rep(i,n){
        if(left[i] >= 0 && right[i] >= 0 && left[i] == right[i]){
            out(i+1);
        }
    }
}
