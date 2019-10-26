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

int dp[11][2334], sum[11][2334];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, c, g;
  cin>>n>>k;
  vi cg[10];
  REP(i, n){
    cin>>c>>g;
    cg[g-1].push_back(c);
  }
  REP(i, 10){
    if(!cg[i].size()){
      break;
    }
    sort(ALL(cg[i]), greater<int>());
    REP(j, cg[i].size()){
      sum[i][j+1]=sum[i][j]+cg[i][j];
    }
  }
  int tmp=0;
  REP(i, 10){
    if(!cg[i].size()){
      break;
    }
    tmp=i+1;
    REP(j, k+1){
      REP(l, cg[i].size()){
        if(j+l+1>k){
          break;
        }
        dp[i+1][j+l+1]=max({dp[i+1][j+l+1], dp[i][j+l+1], dp[i][j]+sum[i][l+1]+(l+1)*l});
      }
    }
  }
  cout<<dp[tmp][k]<<'\n';
  return 0;
}
