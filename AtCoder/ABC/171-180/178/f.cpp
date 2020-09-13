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

int numa[252521], numb[252521];
int rana[252521][2], ranb[252521][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[252521], b[252521];
  cin>>n;
  REP(i, n){
    cin>>a[i];
    ++numa[a[i]];
  }
  REP(i, n){
    cin>>b[i];
    ++numb[b[i]];
  }
  FOR(i, 1, n+1){
    if(numa[i]>n-numb[i]){
      cout<<"No"<<'\n';
      return 0;
    }
  }
  FOR(i, 1, n+1){
    rana[i][0]=rana[i][1]=-1;
    ranb[i][0]=ranb[i][1]=-1;
  }
  REP(i, n){
    if(rana[a[i]][0]==-1){
      rana[a[i]][0]=i;
    }
    rana[a[i]][1]=i;
  }
  REP(i, n){
    if(ranb[b[i]][0]==-1){
      ranb[b[i]][0]=i;
    }
    ranb[b[i]][1]=i;
  }
  int ma=0;
  REP(i, n){
    if(!numb[a[i]]){
      continue;
    }
    if(ranb[a[i]][0]<=rana[a[i]][1]){
      CHMAX(ma, rana[a[i]][1]-ranb[a[i]][0]+1);
      // DEBUG(rana[a[i]][1]-ranb[a[i]][0]);
    }
  }
  rotate(b, b+n-ma, b+n);
  cout<<"Yes"<<'\n';
  REP(i, n){
    cout<<b[i]<<" \n"[i==n-1];
  }
  return 0;
}
