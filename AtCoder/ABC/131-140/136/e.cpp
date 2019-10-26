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

// 約数を求める
vl divisor(ll n){
  vl res;
  for(ll i=1; i*i<=n; ++i){
    if(n%i==0){
      res.push_back(i);
      if(i!=n/i){
        res.push_back(n/i);
      }
    }
  }
  return res;
}

const ll INF=1e18;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  ll k, a[525];
  cin>>n>>k;
  ll sum=0, ma=0;
  REP(i, n){
    cin>>a[i];
    sum+=a[i];
    CHMAX(ma, a[i]);
  }
  sort(a, a+n);
  vl v=divisor(sum);
  ll ans=1;
  for(auto &x : v){
    if(x==1){
      continue;
    }
    if(x==sum){
      if(sum-ma<=k){
        ans=x;
      }
      continue;
    }
    vl b;
    REP(i, n){
      if(a[i]%x==0){
        continue;
      }
      b.push_back(a[i]%x);
    }
    sort(ALL(b));
    int m=b.size();
    ll sum[2][525];
    sum[0][0]=0;
    REP(i, m){
      sum[0][i+1]=sum[0][i]+b[i];
    }
    sum[1][m]=0;
    FORR(i, 0, m){
      sum[1][i]=sum[1][i+1]+x-b[i];
    }
    ll tmp=INF;
    REP(i, m+1){
      if(abs(sum[0][i]-sum[1][i])%x==0){
        CHMIN(tmp, max(sum[0][i], sum[1][i]));
      }
    }
    if(tmp<=k){
      CHMAX(ans, x);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
