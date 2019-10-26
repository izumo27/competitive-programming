#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int w, h, n, i;
  int x[110], y[110], a[110];
  cin>>w>>h>>n;
  int maxx=0, minx=w, maxy=0, miny=h;
  for(i=0; i<n; i++) cin>>x[i]>>y[i]>>a[i];
  for(i=0; i<n; i++){
    if(a[i]==1 && x[i]>maxx) maxx=x[i];
    if(a[i]==2 && x[i]<minx) minx=x[i];
    if(a[i]==3 && y[i]>maxy) maxy=y[i];
    if(a[i]==4 && y[i]<miny) miny=y[i];
  }
  if((minx-maxx)>0 && (miny-maxy)>0) cout<<(minx-maxx)*(miny-maxy)<<endl;
  else cout<<0<<endl;
  return 0;
}