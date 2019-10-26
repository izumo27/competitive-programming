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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  string s[12525];
  cin>>n;
  int a=0, b=0, ans=0, ba=0;
  REP(i, n){
    cin>>s[i];
    if(s[i][0]=='B'){
      ++b;
    }
    int sz=s[i].size();
    if(s[i][sz-1]=='A'){
      ++a;
    }
    if(s[i][0]=='B' && s[i][sz-1]=='A'){
      ++ba;
    }
    bool flag=false;
    REP(j, sz){
      if(s[i][j]=='A'){
        flag=true;
      }
      if(flag && s[i][j]=='B'){
        ++ans;
        flag=false;
      }
      if(s[i][j]!='A'){
        flag=false;
      }
    }
  }
  if(a==ba && b==ba){
    ans+=max(0, min(a, b)-1);
  }
  else{
    ans+=min(a, b);
  }
  cout<<ans<<'\n';
  return 0;
}
