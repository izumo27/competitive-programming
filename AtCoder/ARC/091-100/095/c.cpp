#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  int x[210000];
  cin>>n;
  for(int i=0; i<n; i++) cin>>x[i];
  int y[210000];
  for(int i=0; i<n; i++) y[i]=x[i];
  sort(y, y+n);
  for(int i=0; i<n; i++){
    if(x[i]<=y[(n/2)-1]) cout<<y[n/2]<<endl;
    else cout<<y[(n/2)-1]<<endl;
  }
  return 0;
}
