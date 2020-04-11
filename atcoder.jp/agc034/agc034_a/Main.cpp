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
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

signed main()
{   
    gearup;
    int n,a,b,c,d; cin >>n>>a>>b>>c>>d;
    a--;b--;c--;d--;
    string s; cin >> s;
    bool is_res = false;
    if(c<d){
        bool is_c = true;
        bool is_d = true;
        for(int i=b;i+1<=d;i++){
            if(s[i]!='.'&&s[i+1]!='.')is_d=false;
        }
        for(int i=a;i+1<=c;i++){
            if(s[i]!='.'&&s[i+1]!='.')is_c=false;
        }
        if(is_c&&is_d)is_res = true;
    }
    else{
        //bからdまで3つマスが必要
        s=s+'#';
        for(int i=b;i<=d;i++){
            if(s[i-1]=='.' && s[i]=='.' && s[i+1]=='.')is_res=true;
        }
    }
    
    if(is_res)cout << "Yes" << endl;
    else cout << "No" << endl;
}
