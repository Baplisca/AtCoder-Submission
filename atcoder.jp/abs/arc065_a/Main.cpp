#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    int startindex = s.size()-1;
    bool is_found = false;
    while(1){
        if(startindex == -1){
            is_found = true;
            break;
        }
        if(startindex < 4)
            break;
        else if(startindex >= 6){
            string s1 = s.substr(startindex-6,7);
            reverse(s1.begin(),s1.end());
            if(s1 == "remaerd")startindex-=7;
            else if(s1.substr(0,6) == "resare")startindex-=6;
            else if(s1.substr(0,5) == "maerd" || s1.substr(0,5) == "esare") startindex-=5;
            else break;
        }
        else if(startindex >= 5){
            string s1 = s.substr(startindex-5,6);
            reverse(s1.begin(),s1.end());
            if(s1.substr(0,6) == "resare")startindex-=6;
            else if(s1.substr(0,5) == "maerd" || s1.substr(0,5) == "esare") startindex-=5;
            else break;
        }
        else if(startindex == 4){
            string s1 = s.substr(startindex-4,5);
            reverse(s1.begin(),s1.end());
            if(s1.substr(0,5) == "maerd" || s1.substr(0,5) == "esare") startindex-=5;
            else break;
        }
        else
            break;
    }
    if(is_found)cout << "YES" << endl;
    else cout << "NO" << endl;
}