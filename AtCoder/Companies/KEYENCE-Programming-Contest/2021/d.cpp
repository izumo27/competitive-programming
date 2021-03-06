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

// constexpr ll MOD=1000000007ll;
constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

string s[2][325];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  cin>>n;
  int m=1, ans=0, x;
  REP(i, n){
    m*=2;
    x=i%2;
    int y=(i+1)%2;
    s[x][0]="";
    REP(_, m/2){
      s[x][0]+='A';
    }
    REP(_, m/2){
      s[x][0]+='B';
    }
    REP(j, ans){
      s[x][j+1]=s[y][j]+s[y][j];
    }
    REP(j, ans){
      s[x][j+1+ans]=s[y][j];
      REP(k, m/2){
        s[x][j+1+ans]+=(s[y][j][k]=='A' ? 'B' : 'A');
      }
    }
    ans=1+ans*2;
  }
  cout<<ans<<'\n';
  REP(i, ans){
    cout<<s[x][i]<<'\n';
  }
  return 0;
}
