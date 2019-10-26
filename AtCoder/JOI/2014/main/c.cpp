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

#define CHMIN(a, b) a=min((a), (b))
#define CHMAX(a, b) a=max((a), (b))

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int n;
ll a[214514], sum[214514];

bool is_ok(ll x){
  int m=0, r=0;
  REP(l, n){
    if(m<=l){
      m=l+1;
    }
    while(m<l+n-1 && sum[m]-sum[l]<x){
      ++m;
    }
    if(r<=m){
      r=m+1;
    }
    if(r>=l+n+1){
      continue;
    }
    while(r<l+n && sum[r]-sum[m]<x){
      ++r;
    }
    if(sum[n]-sum[r]+sum[l]>=x){
      return true;
    }
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  ll A;
  REP(i, n){
    cin>>A;
    a[i]=a[i+n]=A;
  }
  REP(i, 2*n){
    sum[i+1]=sum[i]+a[i];
  }
  ll lb=1, ub=1e15;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(is_ok(mid)){
      lb=mid;
    }
    else{
      ub=mid;
    }
  }
  cout<<lb<<'\n';
  return 0;
}
