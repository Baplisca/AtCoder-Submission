#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int,int> num;
  int N;
  cin >> N;
  int a;
  for(int i=0;i<N;i++){
      cin >> a;
      num[a]++;
  }
  
  int max_num = 0;
  int max_key;
  //最大値を見つける処理
  for(auto b:num){
      if(b.second > max_num){
          max_num = b.second;
          max_key = b.first;
      }
  }
 
  cout << max_key <<' ' << max_num << endl;
}
