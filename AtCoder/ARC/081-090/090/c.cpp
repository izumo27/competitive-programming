#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, i, ans=0, tmp=0;
  int a[10][110];
  cin>>n;
  for(i=0; i<n; i++) cin>>a[0][i];
  tmp+=a[0][0];
  for(i=0; i<n; i++){
    cin>>a[1][i];
    tmp+=a[1][i];
  }
  if(n==1){
    cout<<tmp<<endl;
    return 0;
  }
  ans=tmp;
  for(i=1; i<n; i++){
    tmp=tmp+a[0][i]-a[1][i-1];
    ans=max(ans, tmp);
  }
  cout<<ans<<endl;
  return 0;
}
