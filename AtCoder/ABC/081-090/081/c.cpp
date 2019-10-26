#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int n, k, i, ans=0;
  int a[200010];
  int num[200010]={};
  cin>>n>>k;
  for(i=0; i<n; i++) cin>>a[i];
  for(i=0; i<n; i++) num[a[i]]++;
  sort(num+1, num+n+1);
  if(k==n){
    cout<<0<<endl;
    return 0;
  }
  for(i=1; i<=n-k; i++) ans+=num[i];
  cout<<ans<<endl;
  return 0;
}