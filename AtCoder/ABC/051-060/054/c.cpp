#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for(int i=0; i<n; ++i)
#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define FORR(i, a, b) for(int i=b-1; i>=a; --i)

int g[50][50];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, a, b;
  cin>>n>>m;
  REP(i, m){
    cin>>a>>b;
    g[a-1][b-1]=g[b-1][a-1]=1;
  }
  int c[10];
  REP(i, n){
    c[i]=i;
  }
  int ans=0;
  do{
    bool ok=true;
    REP(i, n-1){
      if(g[c[i]][c[i+1]]==0){
        ok=false;
        break;
      }
    }
    if(ok) ++ans;
  }while(next_permutation(c+1, c+n));
  cout<<ans<<'\n';
  return 0;
}
