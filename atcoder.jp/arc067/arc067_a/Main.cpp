#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

vector<pair<ll,ll> > res;

//Nについて素因数分解
void factor(int N){
    for(int i=2;i*i <= N;i++){
        
        if(N % i != 0)continue;
        ll count = 0;
        while(N % i == 0){
            count++;
            N /= i;
        }
        res.push_back({i,count});
    }
    if(N !=1)res.push_back({N,1});
}
int main()
{
    int N; cin >> N;
    for(int i=N;i>1;i--){
         factor(i);
    }
    
    vector<ll> fac(N+1,0);
    for(auto a:res){
       fac[a.first] +=a.second;
    }

    ll sum = 1;
    for(int i=0;i<=N;i++){
        sum *= (fac[i] + 1);
        sum %= MOD;
    }
    cout << sum << endl;
}
