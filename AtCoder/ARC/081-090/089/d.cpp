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

int b[2525][2525], s[4334][4334];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, x, y;
  char c;
  cin>>n>>k;
  int l=k<<1;
  REP(i, n){
    cin>>x>>y>>c;
    if(c=='W'){
      y+=k;
    }
    ++b[x%l][y%l];
  }
  int m=l<<1;
  REP(i, m){
    REP(j, m){
      s[i+1][j+1]=s[i+1][j]+b[i%l][j%l];
    }
  }
  REP(j, m){
    REP(i, m){
      s[i+1][j+1]+=s[i][j+1];
    }
  }
  int ans=0;
  REP(i, l){
    REP(j, l){
      int cnt1=s[i+k][j+k]-s[i][j+k]-s[i+k][j]+s[i][j];
      int cnt2=s[i+l][j+l]-s[i+k][j+l]-s[i+l][j+k]+s[i+k][j+k];
      CHMAX(ans, cnt1+cnt2);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
