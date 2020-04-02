#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<ll, ll> P;
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

map<int,int> mp; //<元の世界の並び>
map<int,int> mp1; //<Atcoderの並び>

int trans(string s){
    int n = s.size();
    string res = "";
    rep(i,n){
        int a;
        a = mp[s[i] - '0'];
        res += '0' + a;
    }
    return stoi(res);
}
int retrans(string s){
    int n = s.size();
    string res = "";
    rep(i,n){
        int a;
        a = mp1[s[i] - '0'];
        res += '0' + a;
    }
    return stoi(res);
}

signed main()
{   
    gearup;
    rep(i,10){
        int b; cin >> b;
        mp[b] = i;
        mp1[i] = b;
    }

    
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> c(n);
    rep(i,n) c[i] = trans(to_string(a[i]));
    
    sort(all(c));
    rep(i,n){
        int a;
        a = retrans(to_string(c[i]));
        cout << a << endl;
    }
}