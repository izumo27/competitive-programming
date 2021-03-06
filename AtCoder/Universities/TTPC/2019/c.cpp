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
  int n, x, a[525252];
  cin>>n>>x;
  int cnt=0, b=0;
  REP(i, n){
    cin>>a[i];
    if(a[i]==-1){
      ++cnt;
    }
    else{
      b^=a[i];
    }
  }
  if(!cnt && b!=x){
    cout<<-1<<'\n';
    return 0;
  }
  if((b^x)>x){
    int xx=x, bb=b;
    while(xx>0){
      xx/=2;
      bb/=2;
    }
    if(bb || cnt<2){
      cout<<-1<<'\n';
      return 0;
    }
    int f=0;
    REP(i, n){
      if(a[i]==-1){
        if(f==0){
          a[i]=x;
          ++f;
        }
        else if(f==1){
          a[i]=b;
          ++f;
        }
        else{
          a[i]=0;
        }
      }
      cout<<a[i]<<" \n"[i==n-1];
    }
    return 0;
  }
  int f=0;
  REP(i, n){
    if(a[i]==-1){
      if(f){
        a[i]=0;
      }
      else{
        a[i]=b^x;
        ++f;
      }
    }
    cout<<a[i]<<" \n"[i==n-1];
  }
  return 0;
}
