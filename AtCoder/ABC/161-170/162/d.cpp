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

ll rgb[3][4252];
char col[3]={'R', 'G', 'B'};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  string s;
  cin>>n>>s;
  REP(i, n){
    REP(j, 3){
      rgb[j][i+1]=rgb[j][i];
    }
    if(s[i]=='R'){
      ++rgb[0][i+1];
    }
    else if(s[i]=='G'){
      ++rgb[1][i+1];
    }
    else{
      ++rgb[2][i+1];
    }
  }
  ll ans=0;
  REP(i, n){
    FOR(j, i+1, n){
      if(s[i]==s[j]){
        continue;
      }
      bool used[3];
      REP(k, 3){
        used[k]=false;
      }
      int idx=0;
      REP(k, 3){
        if(col[k]==s[i]){
          used[k]=true;
        }
        if(col[k]==s[j]){
          used[k]=true;
        }
        if(!used[k]){
          idx=k;
        }
      }
      ans+=rgb[idx][n]-rgb[idx][j+1];
      if(j+(j-i)<n){
        int jj=j+(j-i);
        if(s[i]!=s[jj] && s[j]!=s[jj]){
          --ans;
        }
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
