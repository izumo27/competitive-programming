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
#define CHMAX(a, b) a=min((a), (b))

const int MOD=1000000007;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a[114514], b[114514], c[114514];
  cin>>n;
  REP(i, n) cin>>a[i];
  REP(i, n) cin>>b[i];
  REP(i, n) cin>>c[i];
  sort(a, a+n);
  sort(c, c+n);
  ll x, y;
  ll ans=0;
  REP(i, n){
    x=lower_bound(a, a+n, b[i])-&a[0];
    y=&c[n-1]-upper_bound(c, c+n, b[i])+1;
    if(x>0 && y>0) ans+=x*y;
  }
  cout<<ans<<'\n';
  return 0;
}
