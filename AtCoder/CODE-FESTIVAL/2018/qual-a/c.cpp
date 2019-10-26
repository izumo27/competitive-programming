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

ll dp[60][4000][2];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  ll a;
  cin>>n>>k;
  int c[60], sum=0;
  REP(i, n){
    cin>>a;
    int tmp=0;
    while(a>0){
      a/=2;
      ++tmp;
    }
    c[i]=tmp;
    sum+=c[i];
  }
  int m=min(sum, k);
  dp[0][0][0]=1;
  REP(i, n){
    REP(j, m+1){
      REP(k, min(c[i], j+1)){
        dp[i+1][j][0]=(dp[i+1][j][0]+dp[i][j-k][0])%MOD;
      }
      REP(k, min(c[i], j)+1){
        dp[i+1][j][1]=(dp[i+1][j][1]+dp[i][j-k][1])%MOD;
      }
      if(j>=c[i]){
        dp[i+1][j][1]=(dp[i+1][j][1]+dp[i][j-c[i]][0])%MOD;
      }
    }
  }
  ll ans=dp[n][m][0];
  REP(i, m+1){
    ans=(ans+dp[n][i][1])%MOD;
  }
  cout<<ans<<'\n';
  return 0;
}
