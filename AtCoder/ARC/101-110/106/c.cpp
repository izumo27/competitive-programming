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

int ans[252521][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m;
  cin>>n>>m;
  if(n==1){
    if(m!=0){
      cout<<-1<<'\n';
      return 0;
    }
    cout<<1<<' '<<2<<'\n';
    return 0;
  }
  if(m>=n-1 || m<0){
    cout<<-1<<'\n';
    return 0;
  }
  int cur=2;
  REP(i, n){
    ans[i][0]=cur;
    ans[i][1]=cur+1;
    cur+=3;
  }
  cur=7;
  while(m>0){
    cur+=3;
    --m;
  }
  ans[0][1]=cur;
  REP(i, n){
    cout<<ans[i][0]<<' '<<ans[i][1]<<'\n';
  }
  return 0;
}
