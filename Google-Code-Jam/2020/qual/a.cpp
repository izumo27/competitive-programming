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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int t;
  cin>>t;
  REP(case_num, t){
    int n, m[125][125];
    cin>>n;
    REP(i, n){
      REP(j, n){
        cin>>m[i][j];
      }
    }
    int k=0;
    REP(i, n){
      k+=m[i][i];
    }
    int r=0;
    REP(i, n){
      bool used[125];
      REP(j, n+1){
        used[j]=false;
      }
      REP(j, n){
        if(used[m[i][j]]){
          ++r;
          break;
        }
        used[m[i][j]]=true;
      }
    }
    int c=0;
    REP(i, n){
      bool used[125];
      REP(j, n+1){
        used[j]=false;
      }
      REP(j, n){
        if(used[m[j][i]]){
          ++c;
          break;
        }
        used[m[j][i]]=true;
      }
    }
    cout<<"Case #"<<case_num+1<<": "<<k<<' '<<r<<' '<<c<<'\n';
  }
  return 0;
}
