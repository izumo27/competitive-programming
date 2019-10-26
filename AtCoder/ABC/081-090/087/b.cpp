#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int a, b, c, x, i, j, k, ans=0;
  cin>>a>>b>>c>>x;
  for(i=0; i<=a; i++){
    for(j=0; j<=b; j++){
      for(k=0; k<=c; k++){
        if(500*i+100*j+50*k==x) ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}