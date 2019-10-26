#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int ans=0;
  string s;
  cin>>s;
  if(s[0]=='1') ans++;
  if(s[1]=='1') ans++;
  if(s[2]=='1') ans++;
  cout<<ans<<endl;
  return 0;
}