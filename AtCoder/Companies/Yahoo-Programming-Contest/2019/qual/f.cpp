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

// const ll MOD=1000000007ll;
 const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

ll dp[4334][4334];
int blew[2525];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin>>s;
  int n=s.size();
  REP(i, n){
    blew[i+1]=blew[i]+(s[i]-'0');
  }
  dp[0][0]=1;
  REP(i, n<<1){
    int bnum=blew[min(i+1, n)];
    int rnum=min(i+1, n)*2-bnum;
    FOR(j, max(1, i+1-rnum), min(bnum, i+1)+1){
      dp[i+1][j]=(dp[i+1][j]+dp[i][j-1])%MOD;
    }
    FOR(j, max(1, i+1-bnum), min(rnum, i+1)+1){
      dp[i+1][i+1-j]=(dp[i+1][i+1-j]+dp[i][i+1-j])%MOD;
    }
  }
  cout<<dp[n<<1][blew[n]]<<'\n';
  return 0;
}
