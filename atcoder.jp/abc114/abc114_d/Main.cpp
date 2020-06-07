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

//nの素因数分解する
map<int,int> mp;
void factorize(ll n){
    map<ll,ll> ret;
    ll x = n;
    for(ll i = 2; i*i<=n;i++){
        while(x % i == 0){
            mp[i]++;
            x /= i;
        }
    }
    if(x != 1)mp[x]++;
    return;
}
vl a;
ll dfs(int idx,int num){
    if(idx == a.size()){
        if(num == 1)return 1;
        else return 0;
    }
    ll res = 0;
    for(int i=1;i<=a[idx];i++){
        if(num % i == 0)res += dfs(idx+1,num/i);
    }
    return res;
}
signed main()
{   
    gearup;
    ll n; cin >> n;
    for(int i = 2;i<=n;i++)factorize(i);
    for(auto m:mp)a.push_back(m.second+1); 
    //debug(a);
    ll res = dfs(0,75);
    out(res);
}
