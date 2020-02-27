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

bool used[125];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m;
  cin>>n>>m;
  string s[125];
  REP(i, n){
    cin>>s[i];
  }
  string ans1="", ans2="", ans3="";
  REP(i, n){
    if(used[i]){
      continue;
    }
    FOR(j, i+1, n){
      if(used[j]){
        continue;
      }
      bool ok=true;
      REP(k, m){
        if(s[i][k]!=s[j][m-k-1]){
          ok=false;
          break;
        }
      }
      if(ok){
        ans1=s[i]+ans1;
        ans2+=s[j];
        used[i]=used[j]=true;
        break;
      }
    }
    if(!used[i]){
      bool ok=true;
      REP(j, m){
        if(s[i][j]!=s[i][m-j-1]){
          ok=false;
        }
      }
      if(ok){
        ans3=s[i];
      }
    }
  }
  string ans=ans1+ans3+ans2;
  int x=ans.size();
  cout<<x<<'\n';
  // DEBUG(ans1);DEBUG(ans2);DEBUG(ans3);
  cout<<ans1+ans3+ans2<<'\n';
  return 0;
}
