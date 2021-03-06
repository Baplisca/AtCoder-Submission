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
typedef long double ld;
typedef long long int ll;
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
    ll n;cin >> n;
    vl d(3);
    rep(i,3)cin>>d[i];
    vpii q;
    rep(i,n){
        string s;cin >> s;
        int a,b;
        if(s == "AB")a = 0,b=1;
        else if(s == "AC")a = 0,b=2;
        else a = 1,b=2;
        q.emplace_back(a,b);
    }
    string res;
    q.emplace_back(0,1); //番兵
    rep(i,n){
        int a = q[i].first;
        int b = q[i].second;
        if(d[a] == 0 && d[b] == 0){
            out("No");
            return 0;
        }
        if(!d[a]){
            d[a]++;
            d[b]--;
            res += 'A'+a;
        }
        else if(!d[b]){
            d[a]--;
            d[b]++;
            res += 'A'+b;
        }
        else{ //1手先を読む必要がある
            int na = q[i+1].first;
            int nb = q[i+1].second;
            if(a == na || a == nb){
                d[a]++;
                d[b]--;
                res += 'A'+a;
            }
            else{
                d[a]--;
                d[b]++;
                res += 'A'+b;
            }
        }
    }
    out("Yes");
    rep(i,n)out(res[i]);
}