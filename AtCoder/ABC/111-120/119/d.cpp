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
  int a, b, q;
  ll s[114514], t[114514];
  cin>>a>>b>>q;
  FOR(i, 1, a+1){
    cin>>s[i];
  }
  FOR(i, 1, b+1){
    cin>>t[i];
  }
  s[0]=t[0]=-1e12;
  s[a+1]=t[b+1]=1e12;
  ll x;
  REP(i, q){
    cin>>x;
    ll *itrs=lower_bound(s, s+a+2, x);
    ll *itrt=lower_bound(t, t+b+2, x);
    ll ans=min({max(*itrs, *itrt)-x, x-min(*(itrs-1), *(itrt-1)), 2*(*itrs-x)+x-*(itrt-1), 2*(*itrt-x)+x-*(itrs-1), 2*(x-*(itrs-1))+*itrt-x, 2*(x-*(itrt-1))+*itrs-x});
    cout<<ans<<'\n';
  }
  return 0;
}
