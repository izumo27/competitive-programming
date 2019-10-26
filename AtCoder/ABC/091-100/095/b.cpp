#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<n; ++i)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  int m;
  cin>>n>>x;
  int a=1100;
  int b=0;
  REP(i, n){
    cin>>m;
    a=min(a, m);
    b+=m;
  }
  cout<<n+(x-b)/a<<'\n';
  return 0;
}
