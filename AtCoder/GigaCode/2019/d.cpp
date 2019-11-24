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

ll sum[130][130];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int h, w;
  ll a[130][130], k, v;
  cin>>h>>w>>k>>v;
  REP(i, h)REP(j, w){
    cin>>a[i][j];
    sum[i+1][j+1]=sum[i+1][j]+a[i][j];
  }
  REP(j, w){
    REP(i, h){
      sum[i+1][j+1]+=sum[i][j+1];
    }
  }
  int ans=0;
  REP(s, h){
    REP(t, w){
      FOR(x, s, h){
        FOR(y, t, w){
          ll tmp=sum[x+1][y+1]-sum[s][y+1]-sum[x+1][t]+sum[s][t];
          if(tmp+(x-s+1)*(y-t+1)*k<=v){
            CHMAX(ans, (x-s+1)*(y-t+1));
          }
        }
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}