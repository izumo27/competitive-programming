#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, i, t, d, m, ans=0;
  cin>>n;
  for(i=0; i<n; i++){
    cin>>t>>d>>m;
    if((t+10)<=d) ans+=m;
  }
  cout<<ans<<endl;
  return 0;
}
