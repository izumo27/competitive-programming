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

const double EPS=1e-9;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

double dp[125][125][125];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(10)<<fixed;
  int a, b, c;
  cin>>a>>b>>c;
  FORR(i, a, 101){
    FORR(j, b, 101){
      FORR(k, c, 101){
        if((i==100 && (j==100 || k==100)) || (j==100 && k==100)){
          continue;
        }
        if(i-1>0){
          if(j!=100 && k!=100){
            double x=(double)(i-1)/(i-1+j+k);
            dp[i-1][j][k]+=x*(1+dp[i][j][k]);
          }
        }
        if(j-1>0){
          if(i!=100 && k!=100){
            double x=(double)(j-1)/(i-1+j+k);
            dp[i][j-1][k]+=x*(1+dp[i][j][k]);
          }
        }
        if(k-1>0){
          if(i!=100 && j!=100){
            double x=(double)(k-1)/(i-1+j+k);
            dp[i][j][k-1]+=x*(1+dp[i][j][k]);
          }
        }
      }
    }
  }
  cout<<dp[a][b][c]<<'\n';
  return 0;
}
