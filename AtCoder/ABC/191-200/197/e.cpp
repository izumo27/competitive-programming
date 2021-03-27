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

#define DEBUG(x) cout<<#x<<": "<<(x)<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

// constexpr ll MOD=1000000007ll;
constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

ll dp[252521][2];
vl y[252521];
constexpr ll INF=1e18;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, c[252521];
  ll x[252521];
  cin>>n;
  REP(i, n){
    cin>>x[i]>>c[i];
    --c[i];
    y[c[i]].push_back(x[i]);
  }
  y[n].push_back(0);
  REP(i, n+2){
    dp[i][0]=dp[i][1]=INF;
  }
  dp[0][0]=dp[0][1]=0;
  int l=0, r=0;
  REP(i, n+1){
    int m=y[i].size();
    if(m==0){
      dp[i+1][0]=dp[i][0];
      dp[i+1][1]=dp[i][1];
      continue;
    }
    sort(ALL(y[i]));
    if(l<y[i][0]){
      CHMIN(dp[i+1][0], dp[i][0]+(y[i][m-1]-y[i][0])*2+y[i][0]-l);
      CHMIN(dp[i+1][1], dp[i][0]+y[i][m-1]-l);
    }
    else if(l<y[i][m-1]){
      CHMIN(dp[i+1][0], dp[i][0]+y[i][m-1]-y[i][0]+y[i][m-1]-l);
      CHMIN(dp[i+1][1], dp[i][0]+y[i][m-1]-y[i][0]+l-y[i][0]);
    }
    else{
      CHMIN(dp[i+1][0], dp[i][0]+l-y[i][0]);
      CHMIN(dp[i+1][1], dp[i][0]+(y[i][m-1]-y[i][0])*2+l-y[i][m-1]);
    }
    if(r<y[i][0]){
      CHMIN(dp[i+1][0], dp[i][1]+(y[i][m-1]-y[i][0])*2+y[i][0]-r);
      CHMIN(dp[i+1][1], dp[i][1]+y[i][m-1]-r);
    }
    else if(r<y[i][m-1]){
      CHMIN(dp[i+1][0], dp[i][1]+y[i][m-1]-y[i][0]+y[i][m-1]-r);
      CHMIN(dp[i+1][1], dp[i][1]+y[i][m-1]-y[i][0]+r-y[i][0]);
    }
    else{
      CHMIN(dp[i+1][0], dp[i][1]+r-y[i][0]);
      CHMIN(dp[i+1][1], dp[i][1]+(y[i][m-1]-y[i][0])*2+r-y[i][m-1]);
    }
    // DEBUG(dp[i+1][0]);
    // DEBUG(dp[i+1][1]);
    l=y[i][0];
    r=y[i][m-1];
  }
  cout<<min(dp[n+1][0], dp[n+1][1]);
  return 0;
}
