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
  int n, w, a[60];
  cin>>n;
  REP(i, n) a[i]=114514;
  REP(i, n){
    cin>>w;
    *lower_bound(a, a+n, w)=w;
    sort(a, a+n);
  }
  cout<<lower_bound(a, a+n, 114514)-&a[0]<<'\n';
  return 0;
}
