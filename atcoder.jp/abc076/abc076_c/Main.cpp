#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i < b; i++)
#define out(x) cout << x << endl
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
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

signed main()
{   
    gearup;
    string s,t;cin>>s>>t;
    int idx = -1;
    for(int i=0;i+t.size()-1<s.size();i++){
        bool is_res = true;
        for(int j=0;j<t.size();j++){
            if(s[i+j] != t[j] && s[i+j] != '?'){
                is_res = false;
                break;
            }
        }
        if(is_res)idx = i;
    }
    if(idx == -1) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    else{
        for(int i=idx;i<idx+t.size();i++)s[i]=t[i-idx];
    }
    rep(i,s.size())if(s[i] == '?')s[i] = 'a';
    out(s);
}
