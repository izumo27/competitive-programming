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

constexpr int INF=(1<<20);
bool used[1252521];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[252521];
  cin>>n;
  REP(i, n){
    cin>>a[i];
  }
  sort(a, a+n);
  REP(i, n-1){
    if(a[i]==a[i+1]){
      if(a[i]==1){
        cout<<0<<'\n';
        return 0;
      }
      for(int j=a[i]; j<INF; j+=a[i]){
        used[j]=true;
      }
    }
  }
  int ans=0;
  REP(i, n){
    if(used[a[i]]){
      continue;
    }
    ++ans;
    for(int j=a[i]; j<INF; j+=a[i]){
      used[j]=true;
    }
    // DEBUG(i);
  }
  cout<<ans<<'\n';
  return 0;
}
