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

int bit[40];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[125252];
  cin>>n;
  REP(i, n){
    cin>>a[i];
    int b=a[i];
    REP(j, 40){
      bit[j]+=(b&1);
      b/=2;
    }
  }
  int ma=-1;
  int ans=-1;
  REP(i, n){
    int b=a[i];
    int tmp=0;
    REP(j, 40){
      if((b&1) && bit[j]==1){
        tmp+=(1<<j);
      }
      b/=2;
    }
    // DEBUG(tmp);
    if(ma<tmp){
      ans=i;
      ma=tmp;
    }
  }
  cout<<a[ans];
  REP(i, n){
    if(i!=ans){
      cout<<' '<<a[i];
    }
  }
  return 0;
}
