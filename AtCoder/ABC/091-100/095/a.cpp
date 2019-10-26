#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<n; ++i)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin>>s;
  int ans=0;
  REP(i, 3){
    if(s[i]=='o') ++ans;
  }
  cout<<700+ans*100<<'\n';
  return 0;
}
