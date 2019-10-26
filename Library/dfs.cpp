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

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int h, w;
char c[514][514];
bool reached[514][514];
bool ok;

void dfs(int x, int y){
  if(c[x][y]=='#' || x<0 || x>=h || y<0 || y>=w) return;
  if(reached[x][y]) return;
  reached[x][y]=true;
  if(c[x][y]=='g'){
    ok=true;
    return;
  }
  c[x][y]='a';
  dfs(x-1, y);
  dfs(x+1, y);
  dfs(x, y-1);
  dfs(x, y+1);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>h>>w;
  int a, b;
  REP(i, h){
    REP(i, w) cin>>c[i][j];
  }
  REP(i, h){
    REP(j, w){
      if(c[i][j]=='s'){
          a=i;
          b=j;
      }
    }
  }
  dfs(a, b);
  ok ? cout<<"Yes"<<'\n' : cout<<"No"<<'\n';
  return 0;
}
