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

#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int n;
ll a[60];

bool is_ok(ll mid){
  ll sum=0;
  // x*n-(mid-x)>=a[i]-(n-1)
  REP(i, n){
    if(a[i]-(n-1)+mid-1>=0){
      sum+=(a[i]-(n-1)+mid-1)/(n+1)+1;
    }
    if(sum>mid){
      return false;
    }
  }
  return sum<=mid;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>n;
  REP(i, n){
    cin>>a[i];
  }
  ll lb=-1, ub=1e18;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(is_ok(mid)){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }
  // DEBUG(ub);
  ll ans=0;
  // ubの近いところが答えだと信じて適当にループを回す
  for(ll i=max(0ll, ub-500); i<ub+1; ++i){
    if(is_ok(i)){
      ans=i;
      break;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
