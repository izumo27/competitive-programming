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

ll d[252521][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m;
  ll h[252521], w[252521];
  cin>>n>>m;
  REP(i, n){
    cin>>h[i];
  }
  REP(i, m){
    cin>>w[i];
  }
  sort(h, h+n);
  sort(w, w+m);
  REP(i, n-1){
    d[i+1][0]=d[i][0];
    d[i+1][1]=d[i][1];
    if(i&1){
      d[i+1][1]+=h[i+1]-h[i];
    }
    else{
      d[i+1][0]+=h[i+1]-h[i];
    }
  }
  d[n][0]=d[n-1][0];
  d[n][1]=d[n-1][1];
  ll ans=1e18;
  int idx=0;
  REP(i, m){
    while(idx<n-1 && h[idx]<w[i]){
      ++idx;
    }
    ll tmp;
    if(n==1){
      tmp=abs(w[i]-h[0]);
    }
    else if(idx==n-1){
      tmp=d[idx-1][0]+abs(w[i]-h[idx]);
    }
    else if(idx&1){
      tmp=d[idx-1][0]+(w[i]-h[idx-1])+(d[n][1]-d[idx][1]);
      // if(i==0){
      //   DEBUG(d[idx-2][0]);
      //   DEBUG((w[i]-h[idx-1]));
      //   DEBUG(d[n][1]-d[idx][1]);
      // }
    }
    else{
      tmp=d[idx][0]+(h[idx]-w[i])+(d[n][1]-d[idx][1]);
    }
    CHMIN(ans, tmp);
    // DEBUG(tmp);
    // DEBUG(d[n][1]-d[idx+1][1]);
  }
  cout<<ans<<'\n';
  return 0;
}
