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

bool used[5252];
constexpr ll INF=1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, p[5252];
  ll k, c[5252];
  cin>>n>>k;
  REP(i, n){
    cin>>p[i];
    --p[i];
  }
  REP(i, n){
    cin>>c[i];
  }
  ll ans=-INF;
  REP(i, n){
    if(used[i]){
      continue;
    }
    vi ids;
    int idx=i;
    while(!used[idx]){
      ids.push_back(idx);
      used[idx]=true;
      idx=p[idx];
    }
    int m=ids.size();
    ll total=0;
    for(auto& idx : ids){
      total+=c[idx];
    }
    ll ma[5252];
    REP(j, m){
      ma[j]=-INF;
    }
    REP(j, m){
      ll tmp=0;
      REP(k, m){
        CHMAX(ma[k], tmp);
        int idx=(j+k)%m;
        tmp+=c[ids[idx]];
      }
    }
    if(k<m){
      FOR(j, 1, k+1){
        CHMAX(ans, ma[j]);
      }
      continue;
    }
    if(total<0){
      FOR(j, 1, m){
        CHMAX(ans, ma[j]);
      }
      continue;
    }
    REP(j, m){
      if(j<=(k%m)){
        CHMAX(ans, total*(k/m)+ma[j]);
      }
      CHMAX(ans, total*(k/m-1)+ma[j]);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
