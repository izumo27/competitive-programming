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

int n, m;
ll x[114514];

bool is_ok(ll a){
  ll l=-1;
  REP(i, m){
    if(l+1<x[i]-a){
      return false;
    }
    if(l+1>=x[i]){
      if(x[i]+a>=n-1){
        l=n-1;
      }
      else{
        l=max(l, x[i]+a);
      }
    }
    else{
      ll d=x[i]-l-1;
      l=max(l, x[i]+max(a-2*d, (a-d)/2));
    }
    if(l<x[i]){
      return false;
    }
  }
  return l>=n-1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  REP(i, m){
    cin>>x[i];
    --x[i];
  }
  sort(x, x+m);
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
  cout<<ub<<'\n';
  return 0;
}
