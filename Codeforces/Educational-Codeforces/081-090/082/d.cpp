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
  int t;
  cin>>t;
  while(t--){
    ll n;
    int m;
    cin>>n>>m;
    ll sum=0;
    int bit[60];
    REP(i, 60){
      bit[i]=0;
    }
    REP(i, m){
      ll a;
      cin>>a;
      sum+=a;
      int cnt=0;
      while(a>0){
        ++cnt;
        a/=2;
      }
      ++bit[cnt-1];
    }
    if(sum<n){
      cout<<-1<<'\n';
      continue;
    }
    int ans=0;
    REP(i, 60){
      if(n&1){
        if(bit[i]==0){
          FOR(j, i+1, 60){
            if(bit[j]>0){
              --bit[j];
              ans+=j-i;
              FOR(k, i+1, j){
                ++bit[k];
              }
              break;
            }
          }
        }
        else{
          --bit[i];
        }
      }
      if(i!=60){
        bit[i+1]+=bit[i]/2;
      }
      n/=2;
    }
    cout<<ans<<'\n';
  }
  return 0;
}
