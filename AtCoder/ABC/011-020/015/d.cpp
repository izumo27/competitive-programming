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
#define CHMAX(a, b) a=min((a), (b))

const int MOD=1000000007;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int dp[60][60][12525];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, n, k, a[60], b[60];
  cin>>w>>n>>k;
  REP(i, n) cin>>a[i]>>b[i];
  REP(i, n){
    REP(j, k){
      REP(l, w+1){
        if(l<a[i]) dp[i+1][j+1][l]=dp[i][j+1][l];
        else dp[i+1][j+1][l]=max(dp[i][j+1][l], dp[i][j][l-a[i]]+b[i]);
      }
    }
  }
  cout<<dp[n][k][w]<<'\n';
  return 0;
}
