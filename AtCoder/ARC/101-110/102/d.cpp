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

int x[30];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l;
  cin>>l;
  int m=l;
  int cnt=0;
  int cnt2=0;
  while(m){
    if(m&1){
      x[cnt]=1;
      ++cnt2;
    }
    ++cnt;
    m>>=1;
  }
  cout<<20<<' '<<19+cnt-1+cnt2-1<<'\n';
  REP(i, 19){
    cout<<i+1<<' '<<i+2<<' '<<0<<'\n';
  }
  REP(i, cnt-1){
    cout<<i+1<<' '<<i+2<<' '<<(1<<i)<<'\n';
  }
  FORR(i, 0, cnt-1){
    if(x[i]){
      l-=(1<<i);
      cout<<i+1<<' '<<20<<' '<<l<<'\n';
    }
  }
  return 0;
}
