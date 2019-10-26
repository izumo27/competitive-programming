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

int dp[334][334];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin>>s;
  int n=s.size();
  REP(i, n+1){
    REP(l, n-i+1){
      int r=l+i;
      FOR(j, l+1, r){
        dp[l][r]=max(dp[l][r], dp[l][j]+dp[j][r]);
      }
      if(dp[l][r]!=r-l){
        continue;
      }
      REP(j, 4){
        if(l-j<0 || r+3-j>n){
          continue;
        }
        string iwi="";
        FOR(k, l-j, l){
          iwi+=s[k];
        }
        FOR(k, r, r+3-j){
          iwi+=s[k];
        }
        if(iwi=="iwi"){
          dp[l-j][r+3-j]=max(dp[l-j][r+3-j], r-l+3);
        }
      }
    }
  }
  cout<<dp[0][n]/3<<'\n';
  return 0;
}
