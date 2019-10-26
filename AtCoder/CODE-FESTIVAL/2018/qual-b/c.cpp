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

bool used[1333][1333];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  char ans[1333][1333];
  REP(i, n){
    REP(j, n){
      ans[i][j]='.';
    }
  }
  int k=3;
  REP(i, n){
    k=(k+2)%5;
    for(int j=k; j<n; j+=5){
      ans[i][j]='X';
      used[i][j]=true;
      if(i-1>=0){
        used[i-1][j]=true;
      }
      if(j-1>=0){
        used[i][j-1]=true;
      }
      if(j+1<n){
        used[i][j+1]=true;
      }
      if(i+1<n){
        used[i+1][j]=true;
      }
    }
  }
  REP(i, n){
    REP(j, n){
      if(!used[i][j]){
        ans[i][j]='X';
      }
      cout<<ans[i][j];
    }
    cout<<'\n';
  }
  return 0;
}
