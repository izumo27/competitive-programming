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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, k;
  cin>>a>>b>>c>>k;
  int x=max(a, b);
  x=max(x, c);
  int y=x<<k;
  cout<<y+a+b+c-x<<'\n';
  return 0;
}
