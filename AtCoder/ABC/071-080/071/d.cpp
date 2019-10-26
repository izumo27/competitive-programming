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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s1, s2;
  cin>>n>>s1>>s2;
  int s=0;
  ll ans;
  bool width=false;
  if(s1[0]!=s2[0]){
    ans=6;
    width=true;
    s=2;
  }
  else{
    ans=3;
    s=1;
  }
  FOR(i, s, n){
    if(s1[i]!=s2[i]){
      ++i;
      if(width){
        ans=(ans*3)%MOD;
      }
      else{
        ans=(ans*2)%MOD;
        width=true;
      }
    }
    else{
      if(!width){
        ans=(ans*2)%MOD;
      }
      width=false;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
