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
  int T;
  cin>>T;
  REP(case_num, T){
    cout<<"Case #"<<case_num+1<<": ";
    int X, Y;
    cin>>X>>Y;
    string M;
    cin>>M;
    int n=M.size();
    int x=X, y=Y;
    bool ok=false;
    REP(i, n+1){
      if(abs(x)+abs(y)<=i){
        cout<<i<<'\n';
        ok=true;
        break;
      }
      if(i<n){
        if(M[i]=='N'){
          ++y;
        }
        else if(M[i]=='S'){
          --y;
        }
        else if(M[i]=='E'){
          ++x;
        }
        else{
          --x;
        }
      }
    }
    if(!ok){
      cout<<"IMPOSSIBLE"<<'\n';
    }
  }
  return 0;
}
