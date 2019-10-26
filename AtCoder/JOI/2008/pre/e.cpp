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

const int MOD=100000;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int r, c, a[20][12525], flip[20][12525], ans;

void calc(){
  int tmp=0;
  REP(i, c){
    int cnt=0;
    REP(j, r){
      if((a[j][i]+flip[j][i])&1){
        ++cnt;
      }
    }
    tmp+=max(cnt, r-cnt);
  }
  ans=max(ans, tmp);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>r>>c;
  REP(i, r){
    REP(j, c){
      cin>>a[i][j];
    }
  }
  ans=0;
  REP(i, 1<<r){
    REP(j, r){
      int b=i>>j&1;
      REP(k, c){
        flip[j][k]=b;
      }
    }
    calc();
  }
  cout<<ans<<'\n';
  return 0;
}
