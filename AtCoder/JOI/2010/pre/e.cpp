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

const int MOD=100000;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

// 縦、横、向き、曲がったか
int dp[114][114][2][2];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, h;
  cin>>w>>h;
  REP(i, h){
    dp[i][0][0][0]=1;
  }
  REP(j, w){
    dp[0][j][1][0]=1;
  }
  FOR(i, 1, h){
    FOR(j, 1, w){
      dp[i][j][0][0]=(dp[i][j][0][0]+dp[i-1][j][0][0]+dp[i-1][j][0][1])%MOD;
      dp[i][j][0][1]=(dp[i][j][0][1]+dp[i-1][j][1][0])%MOD;
      dp[i][j][1][0]=(dp[i][j][1][0]+dp[i][j-1][1][0]+dp[i][j-1][1][1])%MOD;
      dp[i][j][1][1]=(dp[i][j][1][1]+dp[i][j-1][0][0])%MOD;
    }
  }
  int ans=0;
  REP(i, 2){
    REP(j, 2){
      ans+=dp[h-1][w-1][i][j];
      if(ans>=MOD){
        ans-=MOD;
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
