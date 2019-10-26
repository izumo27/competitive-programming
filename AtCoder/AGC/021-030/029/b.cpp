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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll a[214514];
  cin>>n;
  REP(i, n){
    cin>>a[i];
  }
  sort(a, a+n);
  int ans=0;
  map<ll, int> used;
  FORR(i, 0, n){
    ll m=2*a[i];
    if(!(m&(m-1))){
      int tmp=upper_bound(a, a+n, a[i])-lower_bound(a, a+n, a[i]);
      if(tmp>0 && tmp-used[a[i]]-1>0){
        ++ans;
        used[a[i]]+=2;
      }
    }
    else{
      m=a[i];
      int cnt=0;
      while(m>0){
        m/=2;
        ++cnt;
      }
      ll beki=1ll<<cnt;
      ll b=beki-a[i];
      int tmp1=upper_bound(a, a+n, a[i])-lower_bound(a, a+n, a[i]);
      if(tmp1-used[a[i]]<=0){
        continue;
      }
      int tmp=upper_bound(a, a+n, b)-lower_bound(a, a+n, b);
      if(tmp>0 && tmp-used[b]>0){
        ++ans;
        ++used[b];
        ++used[a[i]];
      }
    }
    // DEBUG(ans);
  }
  cout<<ans<<'\n';
  return 0;
}
