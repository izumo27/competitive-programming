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

ll sumx[20], dp[1<<20][20], dp2[1<<20];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll x[20], c[20], v[20];
  cin>>n;
  REP(i, n){
    cin>>x[i];
  }
  REP(i, n){
    cin>>c[i];
  }
  REP(i, n){
    cin>>v[i];
  }
  REP(i, n){
    sumx[i+1]=sumx[i]+x[i];
  }
  FORR(i, 0, (1<<n)-1){
    ll tmpv=0ll, tmpc=0ll;
    REP(j, n){
      if(!(i>>j&1)){
        tmpv+=v[j];
        tmpc+=c[j];
      }
    }
    REP(j, n+1){
      if(tmpc<=sumx[j]){
        dp[i][j]=tmpv;
      }
      else{
        REP(k, n){
          if(i>>k&1){
            continue;
          }
          CHMAX(dp[i][j], dp[i|1<<k][j]);
        }
      }
    }
  }
  FORR(i, 0, (1<<n)-1){
    int sz=0;
    ll tmp=1e18;
    REP(j, n){
      if(i>>j&1){
        ++sz;
      }
      else{
        CHMIN(tmp, dp2[i|1<<j]);
      }
    }
    dp2[i]=max(dp[i][sz], tmp);
  }
  cout<<dp2[0]<<'\n';
  return 0;
}
