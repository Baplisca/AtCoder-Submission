#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;

vector<pair<ll,ll> > res;

//Nについて素因数分解
void factor(ll N){
    for(ll i=2;i*i <= N;i++){
        
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
    ll n,p; cin >> n >> p;
    factor(p);
    ll gcd = 1;
    for(auto a:res){
        for(int i=0;i<a.second/n;i++)gcd *= a.first;
    }
    cout << gcd << endl;
}
