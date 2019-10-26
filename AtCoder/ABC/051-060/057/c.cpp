#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(ll a, ll b){
  int counta=0, countb=0;
  while(a>0){
    a/=10;
    counta++;
  }
  while(b>0){
    b/=10;
    countb++;
  }
  return max(counta, countb);
}

int main(){
  ll n, a, b;
  int ans=10;
  cin>>n;
  for(a=1; a*a<=n; a++){
    if(n%a==0){
      b=n/a;
      ans=min(ans, f(a, b));
    }
  }
  cout<<ans<<endl;
  return 0;
}