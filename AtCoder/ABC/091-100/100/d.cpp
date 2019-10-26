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
  int n, m;
  ll x, y, z, xyz[10][1252];
  cin>>n>>m;
  REP(i, n){
    cin>>x>>y>>z;
    xyz[0][i]=x+y+z;
    xyz[1][i]=x+y-z;
    xyz[2][i]=x-y+z;
    xyz[3][i]=-x+y+z;
    xyz[4][i]=x-y-z;
    xyz[5][i]=-x+y-z;
    xyz[6][i]=-x-y+z;
    xyz[7][i]=-x-y-z;
  }
  REP(i, 8){
    sort(xyz[i], xyz[i]+n, greater<ll>());
  }
  ll ans=0;
  REP(i, 8){
    ll tmp=0;
    REP(j, m){
      tmp+=xyz[i][j];
    }
    ans=max(ans, tmp);
  }
  cout<<ans<<'\n';
  return 0;
}
