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

const double EPS=1e-9;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int t;
  cin>>t;
  REP(case_num, t){
    int n, s[1252], e[1252];
    cin>>n;
    REP(i, n){
      cin>>s[i]>>e[i];
    }
    vi ord(n);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&s, &e](int x, int y){
      if(s[x]==s[y]) return e[x]<e[y];
      return s[x]<s[y];
    });
    int c=0, j=0;
    char ans[1252];
    bool ok=true;
    REP(i, n){
      if(c<=s[ord[i]]){
        c=e[ord[i]];
        ans[ord[i]]='C';
      }
      else if(j<=s[ord[i]]){
        j=e[ord[i]];
        ans[ord[i]]='J';
      }
      else{
        cout<<"Case #"<<case_num+1<<": "<<"IMPOSSIBLE"<<'\n';
        ok=false;
        break;
      }
    }
    if(!ok){
      continue;
    }
    cout<<"Case #"<<case_num+1<<": ";
    REP(i, n){
      cout<<ans[i];
    }
    cout<<'\n';
  }
  return 0;
}
