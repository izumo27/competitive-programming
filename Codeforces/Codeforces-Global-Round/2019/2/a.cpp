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

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int n, c[364364];
int used[364364][2];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>n;
  int cnt=0;
  pii mi[2];
  REP(i, n){
    cin>>c[i];
    if(cnt<2 && !used[c[i]][0]){
      used[c[i]][0]=1;
      mi[cnt++]=pii(i, c[i]);
    }
  }
  cnt=0;
  pii ma[2];
  FORR(i, 0, n){
    if(cnt<2 && !used[c[i]][1]){
      used[c[i]][1]=1;
      ma[cnt++]=pii(i, c[i]);
    }
  }
  int ans=0;
  // DEBUG(mi[0].first);
  // DEBUG(ma[0].first);
  if(mi[0].second!=ma[0].second){
    ans=ma[0].first-mi[0].first;
  }
  else{
    ans=max(ma[0].first-mi[1].first, ma[1].first-mi[0].first);
  }
  cout<<ans<<'\n';
  return 0;
}
