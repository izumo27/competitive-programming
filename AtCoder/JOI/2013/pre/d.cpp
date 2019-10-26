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

const int MOD=1000000007;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int dp[210][110];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int d, n, t[210], a[210], b[210], c[210];
  cin>>d>>n;
  REP(i, d){
    cin>>t[i];
  }
  REP(i, n){
    cin>>a[i]>>b[i]>>c[i];
  }
  memset(dp, -1, sizeof(dp));
  REP(i, n){
    if(a[i]<=t[0] && t[0]<=b[i]){
      dp[1][c[i]]=0;
    }
  }
  FOR(i, 1, d){
    REP(j, 101){
      if(dp[i][j]<0) continue;
      REP(k, n){
        if(a[k]<=t[i] && t[i]<=b[k]){
          dp[i+1][c[k]]=max(dp[i+1][c[k]], dp[i][j]+abs(j-c[k]));
        }
      }
    }
  }
  int ans=0;
  REP(i, 101){
    ans=max(ans, dp[d][i]);
  }
  cout<<ans<<'\n';
  return 0;
}
