#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int len, i, j;
  string s;
  cin>>s;
  len=s.length();
  for(i=0; i<len; i++){
    for(j=0; j<len; j++){
      if(s[i]==s[j] && i!=j) {
        cout<<"no"<<endl;
        return 0;
      }
    }
  }
  cout<<"yes"<<endl;
  return 0;
}