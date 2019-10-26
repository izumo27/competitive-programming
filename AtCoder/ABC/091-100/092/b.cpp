#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int n, d, x, i, ans=0;
  int a[110];
  cin>>n>>d>>x;
  for(i=0; i<n; i++) cin>>a[i];
  for(i=0; i<n; i++){
    ans+=(d-1)/a[i]+1;
  }
  cout<<ans+x<<endl;
  return 0;
}