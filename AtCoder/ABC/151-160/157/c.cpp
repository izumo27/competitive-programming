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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m, s[10], C[10];
  cin>>n>>m;
  REP(i, m){
    cin>>s[i]>>C[i];
    --s[i];
  }
  int ans=-1;
  REP(i, 1000){
    int x=i;
    int a=x/100;
    int b=(x-a*100)/10;
    int c=x%10;
    // DEBUG(a);DEBUG(b);DEBUG(c);
    bool ok=true;
    int cnt=0;
    if(x==0){
      cnt=1;
    }
    while(x>0){
      x/=10;
      ++cnt;
    }
    if(cnt!=n){
      continue;
    }
    REP(j, m){
      if(n==3 && s[j]==0){
        if(C[j]!=a){
          ok=false;
          break;
        }
      }
      if((n==3 && s[j]==1) || (n==2 && s[j]==0)){
        if(C[j]!=b){
          ok=false;
          break;
        }
      }
      if((n==3 && s[j]==2) || (n==2 && s[j]==1) || (n==1 && s[j]==0)){
        if(C[j]!=c){
          ok=false;
          break;
        }
      }
    }
    if(ok){
      ans=i;
      break;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
