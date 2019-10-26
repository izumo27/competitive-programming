#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int n, i, j;
  cin>>n;
  double x[n], y[n], len=0.0, xylen;
  for(i=0; i<n; i++) cin>>x[i]>>y[i];
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      xylen=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
      if(len<xylen) len=xylen;
    }
  }
  cout<<sqrt(len)<<endl;
  return 0;
}