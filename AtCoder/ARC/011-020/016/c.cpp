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

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int n, m, c[5], cost[5], idol, p, pr[5][10];
const double INF=1e9;
double dp[1<<10];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(10)<<fixed;
  cin>>n>>m;
  REP(i, m){
    cin>>c[i]>>cost[i];
    REP(j, c[i]){
      cin>>idol>>p;
      pr[i][idol-1]=p;
    }
  }
  REP(i, 1<<n){
    dp[i]=INF;
  }
  dp[(1<<n)-1]=0;
  FORR(i, 0, (1<<n)-1){
    REP(j, m){
      int tmp=0;
      double sum=0;
      REP(k, n){
        if(i>>k&1){
          tmp+=pr[j][k];
        }
        else{
          sum+=pr[j][k]*dp[1<<k|i];
        }
      }
      if(tmp!=100){
        CHMIN(dp[i], (sum+cost[j]*100)/(100-tmp));
      }
    }
  }
  cout<<dp[0]<<'\n';
  return 0;
}
