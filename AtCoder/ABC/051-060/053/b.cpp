#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int a, z, i;
  string s;
  cin>>s;
  for(i=0; i<s.length(); i++){
    if(s[i]=='A'){
      a=i;
      break;
    }
  }
  for(i=s.length()-1; i>0; i--){
    if(s[i]=='Z'){
      z=i;
      break;
    }
  }
  cout<<z-a+1<<endl;
  return 0;
}