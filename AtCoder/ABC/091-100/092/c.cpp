#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int n, i;
  llint sum;
  llint a[110000];
  cin>>n;
  a[0]=0;
  a[n+1]=0;
  for(i=1; i<=n; i++) cin>>a[i];
  for(i=0; i<=n; i++) sum+=abs(a[i+1]-a[i]);
  for(i=1; i<=n; i++){
    // 0, 1, 2, or, 2, 1, 0
    if((a[i-1]<=a[i] && a[i]<=a[i+1]) || (a[i-1]>=a[i] && a[i]>=a[i+1])){
      // cout<<i<<endl;
      cout<<sum<<endl;
    }
    // 0, 2, 1, or, 1, 2, 0
    else if((a[i-1]<=a[i+1] && a[i]>=a[i+1]) || (a[i-1]>=a[i+1] && a[i]<=a[i+1])){
      // cout<<i<<endl;
      cout<<sum-2*(abs(a[i]-a[i+1]))<<endl;
    }
    // 2, 0, 1, or, 1, 0, 2
    else if((a[i-1]>=a[i+1] && a[i-1]<=a[i]) || (a[i-1]>=a[i] && a[i-1]<=a[i+1])){
      // cout<<i<<endl;
      cout<<sum-2*(abs(a[i-1]-a[i]))<<endl;
    }
  }
  return 0;
}