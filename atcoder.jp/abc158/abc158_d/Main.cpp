#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
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

signed main()
{   
    gearup;
    deque<char> c;
    string s;
    int q; cin >> s >> q;
    rep(i,s.size())c.push_back(s[i]);
    int t;
    bool rev = false;
    rep(i,q){
        cin >> t;
        if(t==1){
            rev = !rev;
        }
        else{ //追加
            int f; char c1;
            cin >> f >> c1;
            if(f==1){
                if(rev == false) c.push_front(c1); //先頭に追加
                else c.push_back(c1);
            }
            else {
                if(rev == false) c.push_back(c1);
                else c.push_front(c1);
            }
        }
    }
    if(rev == false){
        for(auto res = c.begin();res!=c.end();res++){
            cout << *res;
        }
    }
    else{
        for(auto res = c.rbegin();res!=c.rend();res++){
            cout << *res;
        }
    }
    cout << endl;
}
