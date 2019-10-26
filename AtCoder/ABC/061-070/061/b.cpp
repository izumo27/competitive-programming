#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int n, m, i;
  int a[60], b[60];
  cin>>n>>m;
  for(i=1; i<=m; i++) cin>>a[i]>>b[i];
  int ans[n];
  for(i=1; i<=n; i++) ans[i]=0;
  for(i=1; i<=m; i++){
    ans[a[i]]++;
    ans[b[i]]++;
  }
  for(i=1; i<=n; i++) cout<<ans[i]<<endl;
  return 0;
}