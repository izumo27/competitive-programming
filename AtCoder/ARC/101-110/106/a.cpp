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

const ull INF=1e18;
ull a[40], b[40];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  ull n;
  cin>>n;
  ull tmp=3;
  int cnta=1;
  while(tmp<INF){
    a[cnta++]=tmp;
    tmp*=3;
  }
  tmp=5;
  int cntb=1;
  while(tmp<INF){
    b[cntb++]=tmp;
    tmp*=5;
  }
  FOR(i, 1, cnta){
    FOR(j, 1, cntb){
      if(a[i]+b[j]==n){
        cout<<i<<' '<<j<<'\n';
        return 0;
      }
    }
  }
  cout<<-1<<'\n';
  return 0;
}
