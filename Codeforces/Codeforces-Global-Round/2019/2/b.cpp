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

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int n, h, a[1333];

bool is_ok(int mid){
  int b[1333];
  REP(i, n){
    b[i]=a[i];
  }
  sort(b, b+min(mid+1, n));
  int flag=1;
  int tmp=0;
  FORR(i, 0, mid+1){
    if(flag&1){
      tmp+=b[i];
      if(tmp>h){
        return false;
      }
    }
    ++flag;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>n>>h;
  REP(i, n){
    cin>>a[i];
  }
  int lb=0, ub=n;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(is_ok(mid)){
      lb=mid;
    }
    else{
      ub=mid;
    }
  }
  cout<<lb+1<<'\n';
  return 0;
}
