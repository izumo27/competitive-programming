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

int dp[2][114514];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, K, a[114];
  cin>>n>>K;
  REP(i, n){
    cin>>a[i];
  }
  REP(i, a[0]){
    dp[0][i]=dp[1][i]=-1;
  }
  REP(i, K+1){
    REP(x, 2){
      int y=(x+1)&1;
      if(dp[x][i]!=0){
        continue;
      }
      bool ok=false;
      REP(j, n){
        if(i<a[j]){
          break;
        }
        if(dp[y][i-a[j]]==-1){
          ok=true;
          break;
        }
      }
      dp[x][i]=(ok ? 1 : -1);
    }
  }
  cout<<(dp[0][K]==1 ? "First" : "Second")<<'\n';
  return 0;
}
