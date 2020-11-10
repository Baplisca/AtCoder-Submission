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
ll pcount(ll x) {return __builtin_popcountll(x);}
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//以降 cin の入力元が 'input.txt' になる
//std::ifstream in("input.txt");
//std::cin.rdbuf(in.rdbuf());


signed main()
{   
    gearup;
    int n; cin >> n;
    vb vacation(366,0);
    map<int,int> month_to_day;
    month_to_day[1]=0;
    month_to_day[2]=31;
    month_to_day[3] = month_to_day[2]+29;
    month_to_day[4]=month_to_day[3]+31;
    month_to_day[5]=month_to_day[4]+30;
    month_to_day[6]=month_to_day[5]+31;
    month_to_day[7]=month_to_day[6]+30;
    month_to_day[8]=month_to_day[7]+31;
    month_to_day[9]=month_to_day[8]+31;
    month_to_day[10]=month_to_day[9]+30;
    month_to_day[11]=month_to_day[10]+31;
    month_to_day[12]=month_to_day[11]+30;
    //休みを設定
    vacation[0] = true;
    for(int i=6;i<366;i+=7){
        vacation[i] = true;
        vacation[i+1] = true;
    }
    rep(i,n){
        string s; cin >> s;
        int idx = s.find("/");
        string s1 = s.substr(0,idx);
        string s2 = s.substr(idx+1,s.size()-(idx+1));
        int num = month_to_day[stoi(s1)] + stoi(s2) -1;
        //out(num);
        if(vacation[num] == false)vacation[num] = true;
        else{
            for(int j = num;j<366;j++){
                if(vacation[j] == false){
                    vacation[j] = true;
                    break;
                }
            }
        }
    }
    //休みの連続区間
    int res = 0;
    int ttl = 0;
    rep(i,366){
        if(vacation[i])ttl++;
        else{
            res = max(res,ttl);
            ttl = 0;
        }
    }
    res = max(res,ttl);
    out(res);
}
