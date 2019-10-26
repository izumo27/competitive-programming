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

const ll INF=1e18;

ll dp[2525][2525];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, a[2525];
  ll s[2525];
  cin>>n>>k;
  s[0]=0ll;
  REP(i, n){
    cin>>a[i];
    s[i+1]=s[i]+(ll)a[i];
  }
  if(s[n]==k){
    cout<<1<<'\n';
    return 0;
  }
  REP(i, n+1){
    FOR(j, 1, n+1){
      if(j==1){
        dp[i][j]=1;
      }
      else{
        dp[i][j]=INF;
      }
    }
  }
  REP(i, n){
    FOR(j, 2, i+2){
      if(dp[i][j-1]>=s[i]){
        dp[i+1][j]=dp[i][j];
      }
      else{
        dp[i+1][j]=min(dp[i][j], dp[i][j-1]+dp[i][j-1]*a[i]/s[i]+1);
      }
    }
  }
  FORR(i, 0, n+1){
    if(dp[n][i]<=(ll)k){
      cout<<i<<'\n';
      return 0;
    }
  }
  return 0;
}
