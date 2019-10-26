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

int n, A, B, C, l[10];

int solve(int bit, int X){
  vi cand;
  int res=1e9;
  REP(i, n){
    if(bit>>i&1){
      cand.push_back(l[i]);
    }
  }
  int sz=cand.size();
  FOR(i, 1, 1<<sz){
    int tmp=0;
    REP(j, sz){
      if(i>>j&1){
        tmp+=cand[j];
      }
    }
    int mp=10*(sz-1);
    CHMIN(res, mp+abs(tmp-X));
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>A>>B>>C;
  REP(i, n){
    cin>>l[i];
  }
  int ans=1e9;
  FOR(i, 1, 1<<n){
    FOR(j, 1, 1<<n){
      FOR(k, 1, 1<<n){
        if(i&j || j&k || k&i){
          continue;
        }
        CHMIN(ans, solve(i, A)+solve(j, B)+solve(k, C));
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
