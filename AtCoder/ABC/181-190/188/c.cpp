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

// constexpr ll MOD=1000000007ll;
constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

bool used[72525];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[72525];
  cin>>n;
  REP(i, 1<<n){
    cin>>a[i];
  }
  int m=(1<<n);
  while(m>0){
    int idx=0;
    while(idx<(1<<n)){
      int x=-1, y;
      if(!used[idx]){
        x=idx;
        ++idx;
      }
      if(x!=-1){
        while(idx<(1<<n)){
          if(!used[idx]){
            y=idx;
            break;
          }
          ++idx;
        }
        if(a[x]<a[y]){
          used[x]=true;
          if(m==2){
            cout<<x+1<<'\n';
            return 0;
          }
        }
        else{
          used[y]=true;
          if(m==2){
            cout<<y+1<<'\n';
            return 0;
          }
        }
      }
      ++idx;
    }
    m/=2;
  }
  return 0;
}
