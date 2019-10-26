#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int i;
  char ch;
  string s;
  cin>>s;
  set<char> values;
  for(i=0; i<s.size(); i++) values.insert(s[i]);
  for(ch='a'; ch<='z'; ch++){
    if(values.find(ch)==values.end()){
      cout<<ch<<endl;
      return 0;
    }
  }
  cout<<"None"<<endl;
  return 0;
}