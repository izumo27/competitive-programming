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

bool check[3][3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int a[3][3], n;
  REP(i, 3){
    REP(j, 3){
      cin>>a[i][j];
    }
  }
  cin>>n;
  REP(i, n){
    int b;
    cin>>b;
    REP(j, 3){
      REP(k, 3){
        if(a[j][k]==b){
          check[j][k]=true;
        }
      }
    }
  }
  bool ok=false;
  REP(i, 3){
    bool ok2=true;
    REP(j, 3){
      if(!check[i][j]){
        ok2=false;
        break;
      }
    }
    if(ok2){
      ok=true;
      break;
    }
  }
  REP(i, 3){
    bool ok2=true;
    REP(j, 3){
      if(!check[j][i]){
        ok2=false;
        break;
      }
    }
    if(ok2){
      ok=true;
      break;
    }
  }
  if(check[0][0] && check[1][1] && check[2][2]){
    ok=true;
  }
  if(check[0][2] && check[1][1] && check[2][0]){
    ok=true;
  }
  cout<<(ok ? "Yes" : "No")<<'\n';
  return 0;
}
