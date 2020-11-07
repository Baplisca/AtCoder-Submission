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

int x[100],y[100];
bool is_card[20][20];
bool is_card2[20][20];
bool is_card3[20][20];
int card_num[20][20];
pair<int,int> card_pos[100];

void move(int &now_x, int &now_y, int to_x, int to_y ,string &res){
    while(now_x < to_x){
        res += 'R';
        now_x++;
    }
    while(now_x > to_x){
        res += 'L';
        now_x--;
    }
    while(now_y < to_y){
        res += 'D';
        now_y++;
    }
    while(now_y > to_y){
        res += 'U';
        now_y--;
    }
}
void greedy(int &now_x, int &now_y,string &res, int &idx){
    move(now_x,now_y,x[idx],y[idx],res);
    res += 'I';
    idx++;
}

void semigreedy_execute(int &now_x, int &now_y,string &res, int &idx, bool is_card2[20][20]){
    int first_x = x[idx+1];
    int first_y = y[idx+1];
    int second_x = x[idx];
    int second_y = y[idx];

    //nowからfirstまではgreedy
    move(now_x,now_y,first_x,first_y,res);
    res += 'I';

    //firstからsecondまでの道中でカードを置く
    //空きマスをsecondから円形に探索する
    int throw_dest_x = -1,throw_dest_y = -1;
    //空きマスが見つかるまで半径を大きくしていく
    bool is_found_throw = false;
    int radi = 1;
    while(!is_found_throw){
        rep(j,8){
            int nx = second_x + (radi*dx[j]);
            int ny = second_y + (radi*dy[j]);
            if(nx < 0 || nx >= 20 || ny < 0 || ny >= 20)continue;
            if(is_card2[nx][ny] == false){
                throw_dest_x = nx;
                throw_dest_y = ny;
                is_found_throw = true;
                break;
            }
        }
        radi++;
    }

    //first (now) からthrow_destまで移動して、カードを置く
    move(now_x,now_y,throw_dest_x,throw_dest_y,res);
    res += 'O';

    //throw_dest (now) からsecondに移動し、カードを拾う
    move(now_x,now_y,second_x,second_y,res);
    res += 'I';

    //secondからthrow_destに移動し、カードを拾う
    move(now_x,now_y,throw_dest_x,throw_dest_y,res);
    res += 'I';

    idx += 2;
}

void semigreedy(int &now_x, int &now_y,string &res2, int &idx){
    int dist1 = abs(x[idx] - now_x) + abs(y[idx] - now_y);
    int dist2 = abs(x[idx+1] - now_x) + abs(y[idx+1] - now_y);
    if(dist1 <= dist2){
        is_card2[x[idx]][y[idx]] = false;
        greedy(now_x,now_y,res2,idx);
        is_card2[x[idx]][y[idx]] = false;
        greedy(now_x,now_y,res2,idx);
    }
    else{
        semigreedy_execute(now_x,now_y,res2,idx,is_card2);
        is_card2[x[idx-2]][y[idx-2]] = false;
        is_card2[x[idx-1]][y[idx-1]] = false;
    }
}

void hybrid(int &now_x, int &now_y,string &res2, int &idx){
    string tmp1 = "";
    string tmp2 = "";
    auto pos1_x = now_x;
    auto pos1_y = now_y;
    auto pos2_x = now_x;
    auto pos2_y = now_y;
    //貪欲版
    {
        greedy(pos1_x,pos1_y,tmp1,idx);
        greedy(pos1_x,pos1_y,tmp1,idx);
        idx-=2;
    }
    //１つ先読み版
    {
        semigreedy_execute(pos2_x,pos2_y,tmp2,idx,is_card3);
    }
    if(tmp1.size() < tmp2.size()){
        now_x = pos1_x;
        now_y = pos1_y;
        res2 += tmp1;
    }
    else{
        now_x = pos2_x;
        now_y = pos2_y;
        res2 += tmp2;
    }
}

signed main() {
    gearup;
    ll n = 100;
    rep(i,20)rep(j,20)card_num[i][j] = -1;
    rep(i,n){
        cin>>y[i]>>x[i];
        is_card[x[i]][y[i]] = true;
        is_card2[x[i]][y[i]] = true;
        is_card3[x[i]][y[i]] = true;
        card_num[x[i]][y[i]] = i;
    }

    //0から99まで集める、貪欲版
    int now_x = 0,now_y = 0;
    int idx = 0;
    string res = "";
    while(1){
        if(idx == 100)break;
        greedy(now_x,now_y,res,idx);
    }
    
    //0から99まで集める時に、1枚だけバッファーを用意する
    //バッファーは欲しい数字より１つ大きくて、距離が近い時発火する
    //0と1、２と３がペアになるようにする
    int now_x2 = 0,now_y2 = 0;
    int idx2 = 0;
    string res2 = "";
    while(1){
        if(idx2 >= 100)break;
        semigreedy(now_x2,now_y2,res2,idx2);
    }


    //上記の貪欲とバッファーのいいとこ取り
    int now_x3 = 0,now_y3 = 0;
    int idx3 = 0;
    string res3 = "";
    while(1){
        if(idx3 >= 100)break;
        hybrid(now_x3,now_y3,res3,idx3);
    }

    //全部回収してから、近場に並べて番号順に回収
    stack<int> st;
    string res4 = "";
    int now_x4 = 0,now_y4 = 0;
    rep(i,20){
        rep(j,20){
            move(now_x4,now_y4,i,j,res4);
            if(card_num[i][j] >= 0){
                st.push(card_num[i][j]);
                res4 += 'I';
            }
        }
    }
    //空きマスに置く
    for(int i=19;i>=0;i--){
        for(int j=19;j>=0;j--){
            int jj = j;
            if(i % 2 == 0)jj = 19 - j;
            int num = st.top();
            st.pop();
            move(now_x4,now_y4,i,jj,res4);
            card_pos[num] = {i,jj};
            res4 += 'O';
            if(st.empty())break;
        }
        if(st.empty())break;
    }
    //番号順に回収
    rep(i,n){
        move(now_x4,now_y4,card_pos[i].first,card_pos[i].second,res4);
        res4 += 'I';
    }
    out(res4);
}   
