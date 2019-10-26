#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int n, a, b, i, j, ans=0, sum;
  cin>>n>>a>>b;
  for(i=1; i<=n; i++){
    sum=0;
    j=i;
    for(;;){
      if(j==0) break;
      sum+=j%10;
      j/=10;
    }
    if(sum>=a && sum<=b) ans+=i;
  }
  cout<<ans<<endl;
  return 0;
}