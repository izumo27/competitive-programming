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

#define DEBUG(x) cout<<#x<<": "<<(x)<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

constexpr ll MOD=1000000007ll;
// constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-9;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int x, y, a, b, c;
  cin>>x>>y>>a>>b>>c;
  int p[125252], q[125252], r[125252];
  pii num[325252];
  REP(i, a){
    cin>>p[i];
    num[i]=pii(p[i], 0);
  }
  REP(i, b){
    cin>>q[i];
    num[i+a]=pii(q[i], 1);
  }
  REP(i, c){
    cin>>r[i];
    num[i+a+b]=pii(r[i], 2);
  }
  sort(num, num+a+b+c);
  ll ans=0;
  int cnt=0, red=0, grn=0;
  FORR(i, 0, a+b+c){
    auto tmp=num[i];
    int u=tmp.first, v=tmp.second;
    bool ok=false;
    if(v==2){
      ok=true;
    }
    if(v==0 && red<x){
      ++red;
      ok=true;
    }
    if(v==1 && grn<y){
      ++grn;
      ok=true;
    }
    if(ok){
      ++cnt;
      ans+=u;
    }
    // DEBUG(ans);
    if(cnt>=x+y){
      break;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
