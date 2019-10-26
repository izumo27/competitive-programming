#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)

#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

#define CHMIN(a, b) a=min((a), (b))
#define CHMAX(a, b) a=max((a), (b))

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, p, q, r, x, y, a[12525], b[12525];
  cin>>n>>m>>p>>q>>r;
  a[0]=1;
  b[0]=r;
  int sz=1;
  REP(i, m){
    cin>>x>>y;
    REP(i, sz){
      if(a[i]<=x && x<b[i]){
        a[sz]=x+1;
        b[sz]=b[i];
        b[i]=x;
        ++sz;
      }
      else if(a[i]<=y && y<b[i]){
        a[sz]=y+1;
        b[sz]=b[i];
        b[i]=y;
        ++sz;
      }
      int d;
      if(b[i]<=x){
        d=n-x;
      }
      else if(b[i]<=y){
        d=n-x-y;
      }
      else{
        d=-y;
      }
      a[i]+=d;
      b[i]+=d;
    }
  }
  int ans=0;
  REP(i, sz){
    ans+=max(0, min(q, b[i])-max(p, a[i])+1);
  }
  cout<<ans<<'\n';
  return 0;
}
