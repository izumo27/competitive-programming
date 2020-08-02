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

constexpr ll INF=1e18;
int n, k;
ll a[252521];

bool isok(ll mid){
  ll cnt=0;
  REP(i, n){
    cnt+=(a[i]-1)/mid;
    if(cnt>k){
      return false;
    }
  }
  return cnt<=k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>n>>k;
  REP(i, n){
    cin>>a[i];
  }
  ll lb=0, ub=INF;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(isok(mid)){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }
  cout<<ub<<'\n';
  return 0;
}
