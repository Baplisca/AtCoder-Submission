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
const long long INF = 1LL << 60;
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}

signed main()
{   
    gearup;
    double a,b,x; cin >> a >> b >> x;
    double s = x/a; //体積を面積に変換
    if(s == a*b){
        //ゼロじょさんが起こるため場合分
        cout << 0 << endl;
    }
    else{
        if(s > a*b/2){ //傾けが45度より小さい時
            double b2 = (2*s/a) -b; //b2は台形の上の幅
            double s1 = a*b2;
            double s2 = s-s1; //s2は残った三角形の面積
            double a2 = 2*s2/(b-b2);
            double rad = atan((b-b2)/a2);
            cout << fixed << setprecision(10) << rad * (180/PI) << endl;
        }
        else{
        double a2 = 2*s/b;
        double rad = atan(b/a2);
        cout << fixed << setprecision(10) << rad * (180/PI)<< endl;
        }
    }
}
