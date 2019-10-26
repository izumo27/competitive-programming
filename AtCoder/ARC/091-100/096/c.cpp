#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<n; ++i)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, x, y;
  cin>>a>>b>>c>>x>>y;
  int m;
  x>y ? m=a : m=b;
  int ans;
  if(a+b<=c*2) ans=a*x+b*y;
  else ans=c*min(x, y)*2+min(m, c*2)*abs(x-y);
  cout<<ans<<'\n';
  return 0;
}
