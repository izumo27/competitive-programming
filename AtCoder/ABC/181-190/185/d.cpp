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

ll n;
int m, a[252521];

bool is_ok(ll mid){
  if(a[0]>0 && a[0]<mid){
    return false;
  }
  REP(i, m-1){
    if(a[i+1]-a[i]>1 && a[i+1]-a[i]-1<mid){
      return false;
    }
  }
  if(a[m-1]!=n-1 && (n-1)-a[m-1]<mid){
    return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>n>>m;
  REP(i, m){
    cin>>a[i];
    --a[i];
  }
  if(m==0){
    cout<<1<<'\n';
    return 0;
  }
  if(m==n){
    cout<<0<<'\n';
    return 0;
  }
  sort(a, a+m);
  ll lb=1, ub=1e9;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(is_ok(mid)){
      lb=mid;
    }
    else{
      ub=mid;
    }
  }
  ll ans=0;
  ll cur=-1;
  REP(i, m){
    if(a[i]!=0){
      ans+=(a[i]-cur-1-1)/lb+1;
    }
    cur=a[i];
  }
  if(a[m-1]!=n-1){
    ans+=(n-1-cur-1)/lb+1;
  }
  cout<<ans<<'\n';
  return 0;
}
