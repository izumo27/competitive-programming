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

int stone[151][1001], dp[151][1001][80], INF=1e9;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k, x, d;
  cin>>n>>m;
  int w=0;
  REP(i, n){
    cin>>k;
    REP(j, k){
      cin>>x>>d;
      stone[i][x-1]=d;
      w=max(w, x);
    }
  }
  REP(i, n){
    REP(j, w){
      REP(l, m+1){
        dp[i][j][l]=INF;
      }
    }
  }
  REP(i, w){
    dp[0][i][0]=0;
    dp[1][i][1]=0;
  }
  REP(i, n-1){
    REP(j, w){
      REP(l, m+1){
        if(stone[i][j]==0 || dp[i][j][l]==INF){
          continue;
        }
        REP(p, w){
          if(stone[i+1][p]==0){
            continue;
          }
          dp[i+1][p][l]=min(dp[i+1][p][l], dp[i][j][l]+(stone[i][j]+stone[i+1][p])*abs(j-p));
        }
        if(i+2>=n || l+1>m){
          continue;
        }
        REP(p, w){
          if(stone[i+2][p]==0){
            continue;
          }
          dp[i+2][p][l+1]=min(dp[i+2][p][l+1], dp[i][j][l]+(stone[i][j]+stone[i+2][p])*abs(j-p));
        }
      }
    }
  }
  int ans=INF;
  REP(i, w){
    REP(j, m){
      ans=min({ans, dp[n-2][i][j], dp[n-1][i][j]});
    }
    ans=min(ans, dp[n-1][i][m]);
  }
  cout<<ans<<'\n';
  return 0;
}
