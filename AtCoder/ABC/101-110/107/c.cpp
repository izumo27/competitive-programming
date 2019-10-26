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
  int n, k;
  ll x[114514];
  cin>>n>>k;
  int z=n;
  bool f=false;
  REP(i, n){
    cin>>x[i];
    if(x[i]>=0 && !f){
      z=i;
      f=true;
    }
  }
  ll ans=1e18;
  if(n-z>=k){
    ans=min(ans, x[z+k-1]);
  }
  if(z>=k){
    ans=min(ans, -x[z-k]);
  }
  FOR(i, z, n){
    if(z>=k-i+z-1){
      ans=min(ans, 2*x[i]-x[i-k+1]);
    }
  }
  REP(i, z){
    if(n-z>=k-z+i){
      ans=min(ans, -2*x[i]+x[k+i-1]);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
