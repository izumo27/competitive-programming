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

ll dp[114514];
int pre[114514], f[114514];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin>>n>>m;
  FOR(i, 1, n+1){
    cin>>f[i];
  }
  dp[0]=1;
  int l=0;
  ll sum=0;
  FOR(r, 1, n+1){
    while(pre[f[r]]>l){
      sum-=dp[l++];
    }
    sum+=dp[r-1];
    dp[r]=sum%MOD;
    pre[f[r]]=r;
  }
  cout<<dp[n]<<'\n';
  return 0;
}
