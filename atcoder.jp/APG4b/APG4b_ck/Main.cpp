#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int total = 1;

  // ここにプログラムを追記
  char c;
  int i=1;
  while(i<S.size()){
      c = S.at(i);
      if(c == '+')
      total++;
      else
      total--;
      i+=2;
  }
  cout <<total<<endl;
}
