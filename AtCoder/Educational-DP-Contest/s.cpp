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

ll dp[114514][2][114];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string K;
  int d;
  cin>>K>>d;
  int n=K.size();
  dp[0][0][0]=1;
  REP(i, n){
    REP(j, 2){
      int x=j ? 9 : K[i]-'0';
      REP(k, d){
        REP(l, x+1){
          dp[i+1][j || l<x][(k+l)%d]=(dp[i+1][j || l<x][(k+l)%d]+dp[i][j][k])%MOD;
        }
      }
    }
  }
  ll ans=0;
  if(dp[n][0][0]+dp[n][1][0]==0){
    ans=(MOD-1)%MOD;
  }
  else{
    ans=(dp[n][0][0]+dp[n][1][0]-1)%MOD;
  }
  cout<<ans<<'\n';
  return 0;
}
