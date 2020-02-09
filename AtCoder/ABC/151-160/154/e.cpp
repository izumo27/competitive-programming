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

ll dp[125][2][4];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  string n;
  int K;
  cin>>n>>K;
  int m=n.size();
  REP(i, m+1){
    REP(j, 2){
      REP(k, K){
        dp[i][j][k]=0;
      }
    }
  }
  dp[0][0][0]=1;
  REP(i, m){
    int D=n[i]-'0';
    REP(j, 2){
      REP(k, K+1){
        for(int d=0; d<=(j ? 9 : D); ++d){
          if(k==K && (d!=0)){
            continue;
          }
          dp[i+1][j||(d<D)][k+(d!=0)]+=dp[i][j][k];
        }
      }
    }
  }
  cout<<dp[m][0][K]+dp[m][1][K]<<'\n';
  return 0;
}
