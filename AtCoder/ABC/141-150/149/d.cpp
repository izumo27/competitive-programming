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

bool ok[125252];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, k, r, s, p;
  string t;
  cin>>n>>k>>r>>s>>p>>t;
  int ans=0;
  REP(i, n){
    bool f=false;
    if(i<k){
      f=true;
    }
    else{
      if(t[i]==t[i-k]){
        if(ok[i-k]){
          f=true;
        }
        else{
          ok[i]=true;
        }
      }
      else{
        f=true;
      }
    }
    if(f){
      if(t[i]=='r'){
        ans+=p;
      }
      if(t[i]=='s'){
        ans+=r;
      }
      if(t[i]=='p'){
        ans+=s;
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
