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

int n, q;
ll a[114514], x;
ll sum[114514], sum2[114514];

bool is_ok(int y){
  int ind=2*y-n+2;
  if(ind>0){
    return abs(x-a[y])<abs(x-a[ind-1]);
  }
  else{
    return y<n/2;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>q;
  REP(i, n){
    cin>>a[i];
    sum[i+1]=sum[i]+a[i];
    if(i&1){
      sum2[i+1]=sum2[i-1]+a[i];
    }
  }
  REP(i, q){
    cin>>x;
    int lb=0, ub=n-1;
    while(ub-lb>1){
      int mid=(lb+ub)/2;
      if(is_ok(mid)){
        lb=mid;
      }
      else{
        ub=mid;
      }
    }
    // DEBUG(lb);
    ll ans=sum[n]-sum[lb+1];
    int ind=2*lb-n+2;
    if(ind>0){
      if(ind&1){
        ans+=sum[ind]-sum2[ind-1];
      }
      else{
        ans+=sum2[ind];
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}
