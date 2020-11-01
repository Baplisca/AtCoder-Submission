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

signed main() {
    gearup;
    string s; cin >> s;
    //1000は8で割れる
    //3桁だけ考える
    //下3桁が8の倍数
    //各文字は1~9のどれか
    vl a(10);
    int n = s.size();
    rep(i,n){
        int num = s[i] - '0';
        a[num]++;
    }
    if(n == 1){
        if(s=="8")out("Yes");
        else out("No");
    }
    else if(n == 2){
        int res1 = stoi(s);
        swap(s[0],s[1]);
        int res2 = stoi(s);
        if(res1 % 8 == 0 || res2 % 8 == 0)out("Yes");
        else out("No");
    }
    else{
        //3桁をピックアップする
        for(int i=1;i<=9;i++){
            auto b = a;
            if(b[i] <= 0)continue;
            b[i]--;
            for(int j=1;j<=9;j++){
                auto c = b;
                if(c[j] <= 0)continue;
                c[j]--;
                for(int k=1;k<=9;k++){
                    if(c[k]){
                        ll num = 100*i + 10*j + k;
                        if(num % 8 == 0){
                            out("Yes");
                            return 0;
                        }
                    }
                }
            }
        }
        out("No");
    }
}   
