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

#define MAX 500000
int L[MAX/2 + 2], R[MAX/2 + 2];
int cnt;


signed main()
{   
    gearup;
    string s; cin >> s;
    ll res;
    map<int,string> mp;
    mp[0] = "Do";
    mp[11] = "Si";
    mp[9] = "La";
    mp[7] = "So";
    mp[5] = "Fa";
    mp[4] = "Mi";
    mp[2] = "Re";
    string t = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
    rep(i,s.size()){
        if(s == t.substr(i,20)){
            res = i;
            break;
        }
    }
    cout << mp[res] << endl;
}