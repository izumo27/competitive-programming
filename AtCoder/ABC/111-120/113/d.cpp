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

ll dp[114][10];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, k;
  cin>>h>>w>>k;
  dp[0][0]=1;
  REP(i, h){
    REP(j, 1<<(w-1)){
      int a[10];
      REP(p, w-1){
        a[p]=0;
      }
      REP(p, w-1){
        if(j>>p&1){
          a[p]=1;
        }
      }
      bool ok=true;
      REP(p, w-2){
        if(a[p]==1 && a[p+1]){
          ok=false;
          break;
        }
      }
      if(!ok){
        continue;
      }
      REP(p, w){
        if(p+1<w && a[p]==1){
          dp[i+1][p]=(dp[i+1][p]+dp[i][p+1])%MOD;
        }
        else if(p-1>=0 && a[p-1]==1){
          dp[i+1][p]=(dp[i+1][p]+dp[i][p-1])%MOD;
        }
        else{
          dp[i+1][p]=(dp[i+1][p]+dp[i][p])%MOD;
        }
      }
    }
  }
  cout<<dp[h][k-1]<<'\n';
  return 0;
}
