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

const int INF=1e9;

int dp[2][51][12525];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, W, C, w, v, c;
  cin>>n>>W>>C;
  vector<pii> wv[50];
  REP(i, n){
    cin>>w>>v>>c;
    wv[c-1].emplace_back(w, v);
  }
  REP(i, 50){
    REP(j, C){
      REP(k, W+1){
        dp[1][j][k]=dp[0][j][k];
      }
    }
    for(auto &a : wv[i]){
      REP(j, C){
        FORR(k, a.first, W+1){
          dp[1][j][k]=max(dp[1][j][k], dp[1][j][k-a.first]+a.second);
        }
      }
    }
    REP(j, C){
      REP(k, W+1){
        dp[0][j+1][k]=max(dp[0][j+1][k], dp[1][j][k]);
      }
    }
  }
  int ans=0;
  REP(i, C+1){
    REP(j, W+1){
      ans=max(ans, dp[0][i][j]);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
