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

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

constexpr double INF=1e9;

double dp[2525];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(10)<<fixed;
  int n, l, x[2525], d[2525];
  double v[2525];
  cin>>n>>l;
  cin>>v[0]>>d[0];
  x[0]=0;
  FOR(i, 1, n+1){
    cin>>x[i]>>v[i]>>d[i];
  }
  x[n+1]=l;
  vi ord(n+2);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&x](int a, int b){
    return x[a]<x[b];
  });
  REP(i, n+2){
    dp[i]=INF;
  }
  dp[0]=0;
  REP(i, n+1){
    FOR(j, i+1, n+2){
      if(x[ord[j]]>x[ord[i]]+d[ord[i]]){
        break;
      }
      CHMIN(dp[ord[j]], dp[ord[i]]+(x[ord[j]]-x[ord[i]])/v[ord[i]]);
    }
  }
  // REP(i, n+1){
  //   cout<<dp[i]<<" \n"[i==n];
  // }
  if(dp[n+1]!=INF){
    cout<<dp[n+1]<<'\n';
  }
  else{
    cout<<"impossible"<<'\n';
  }
  return 0;
}
