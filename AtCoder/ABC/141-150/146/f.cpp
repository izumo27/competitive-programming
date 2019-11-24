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

constexpr ll INF=1e18;
ll dp[125252];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m;
  string s;
  cin>>n>>m>>s;
  REP(i, n+1){
    dp[i]=INF;
  }
  dp[n]=0;
  vi ans;
  int cur=n;
  while(cur>0){
    bool ok=false;
    FOR(i, cur-m, cur){
      if(i<=0){
        dp[0]=dp[cur]+1;
        ans.push_back(cur);
        cur=0;
        ok=true;
        break;
      }
      if(s[i]=='0'){
        dp[i]=dp[cur]+1;
        ans.push_back(cur-i);
        cur=i;
        ok=true;
        break;
      }
    }
    if(!ok){
      break;
    }
  }
  if(dp[0]!=INF){
    int l=ans.size();
    FORR(i, 0, l){
      cout<<ans[i]<<" \n"[i==0];
    }
  }
  else{
    cout<<-1<<'\n';
  }
  return 0;
}
