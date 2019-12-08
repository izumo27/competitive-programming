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

constexpr ll MOD=1000000007ll;
// constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

constexpr int C=36800;
int d[100][100];
bool dp[100][100][73610];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int h, w, a[100][100], b[100][100];
  cin>>h>>w;
  REP(i, h)REP(j, w){
    cin>>a[i][j];
  }
  REP(i, h)REP(j, w){
    cin>>b[i][j];
  }
  REP(i, h)REP(j, w){
    d[i][j]=abs(a[i][j]-b[i][j]);
  }
  REP(i, h)REP(j, w){
    if(i==0 && j==0){
      dp[i][j][d[i][j]+C]=dp[i][j][-d[i][j]+C]=true;
      continue;
    }
    if(i>0){
      REP(k, C*2+1){
        if(dp[i-1][j][k]){
          dp[i][j][k+d[i][j]]=dp[i][j][k-d[i][j]]=true;
        }
      }
    }
    if(j>0){
      REP(k, C*2+1){
        if(dp[i][j-1][k]){
          dp[i][j][k+d[i][j]]=dp[i][j][k-d[i][j]]=true;
        }
      }
    }
  }
  int ans=1e9;
  REP(i, C*2+1){
    if(dp[h-1][w-1][i]){
      CHMIN(ans, abs(i-C));
      if(i>=C){
        break;
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}