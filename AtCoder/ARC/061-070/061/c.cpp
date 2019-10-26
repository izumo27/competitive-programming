#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin>>s;
  int len=s.size();
  ll ans=0;
  if(len==1){
    cout<<s<<endl;
    return 0;
  }
  for(int i=0; i<pow(2, len-1); i++){
    ll tmp=0;
    for(int j=len-2; j>=0; j--){
      tmp=tmp*10+static_cast<ll>(s[len-j-2]-'0');
      if((i>>j)&1){
        ans+=tmp;
        tmp=0;
      }
    }
    ans+=tmp*10+static_cast<ll>(s[len-1]-'0');
  }
  cout<<ans<<endl;
  return 0;
}
