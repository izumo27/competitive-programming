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

int bit[114514][40], kbit[40];
ll dp[50][2];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll k, a;
  cin>>n>>k;
  REP(i, n){
    cin>>a;
    int cnt=0;
    while(a>0){
      bit[i][cnt++]=a&1;
      a/=2;
    }
  }
  int kcnt=0;
  while(k>0){
    kbit[kcnt++]=k&1;
    k/=2;
  }
  REP(i, 50){
    dp[i][0]=dp[i][1]=-1;
  }
  dp[40][0]=0;
  ll beki=1ll<<40;
  FORR(i, 0, 40){
    beki>>=1;
    int cnt=0;
    REP(j, n){
      if(bit[j][i]){
        ++cnt;
      }
    }
    if(dp[i+1][1]>=0){
      dp[i][1]=dp[i+1][1]+beki*max(cnt, n-cnt);
    }
    if(kbit[i]){
      CHMAX(dp[i][1], dp[i+1][0]+beki*cnt);
      dp[i][0]=dp[i+1][0]+beki*(n-cnt);
    }
    else{
      dp[i][0]=dp[i+1][0]+beki*cnt;
    }
  }
  cout<<max(dp[0][0], dp[0][1])<<'\n';
  return 0;
}
