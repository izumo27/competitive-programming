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
  int n, m, p, q, r, x[334], y[334], z[334], flag[334], h[334];
  cin>>n>>m>>p>>q>>r;
  REP(i, r){
    cin>>x[i]>>y[i]>>z[i];
    --x[i];
    --y[i];
  }
  int ans=0, sub=(1<<p)-1;
  while(sub<1<<n){
    REP(i, n){
      flag[i]=sub>>i&1;
    }
    REP(i, m){
      h[i]=0;
    }
    REP(i, r){
      if(flag[x[i]]){
        h[y[i]]+=z[i];
      }
    }
    sort(h, h+m, greater<int>());
    int tmp=0;
    REP(i, q){
      tmp+=h[i];
    }
    ans=max(ans, tmp);
    int a=sub&-sub, b=sub+a;
    sub=((sub&~b)/a>>1)|b;
  }
  cout<<ans<<'\n';
  return 0;
}
