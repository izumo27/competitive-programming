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
  int n, a[125252];
  cin>>n;
  int sum=0;
  REP(i, n){
    cin>>a[i];
    sum+=abs(a[i]);
  }
  if(n==2){
    if((a[0]-a[1])<(a[1]-a[0])){
      cout<<a[1]-a[0]<<'\n';
      cout<<a[1]<<' '<<a[0]<<'\n';
    }
    else{
      cout<<a[0]-a[1]<<'\n';
      cout<<a[0]<<' '<<a[1]<<'\n';
    }
    return 0;
  }
  sort(a, a+n);
  if(a[n-2]>=0 && a[n-1]>=0){
    if(a[0]>=0){
      cout<<sum-2*a[0]<<'\n';
    }
    else{
      cout<<sum<<'\n';
    }
    int tmp=0;
    cout<<a[0]<<' '<<a[n-1]<<'\n';
    tmp=a[0]-a[n-1];
    int idx=0;
    FORR(i, 1, n-2){
      if(a[i]<0){
        idx=i;
        break;
      }
      cout<<tmp<<' '<<a[i]<<'\n';
      tmp-=a[i];
    }
    cout<<a[n-2]<<' '<<tmp<<'\n';
    tmp=a[n-2]-tmp;
    FOR(i, 1, idx+1){
      cout<<tmp<<' '<<a[i]<<'\n';
      tmp-=a[i];
    }
  }
  else if(a[n-1]>=0){
    cout<<sum<<'\n';
    cout<<a[n-1]<<' '<<a[0]<<'\n';
    int tmp=a[n-1]-a[0];
    FOR(i, 1, n-1){
      cout<<tmp<<' '<<a[i]<<'\n';
      tmp-=a[i];
    }
  }
  else{
    cout<<sum+2*a[n-1]<<'\n';
    int tmp=0;
    cout<<a[n-1]<<' '<<a[n-2]<<'\n';
    tmp=a[n-1]-a[n-2];
    FORR(i, 0, n-2){
      cout<<tmp<<' '<<a[i]<<'\n';
      tmp-=a[i];
    }
  }
  return 0;
}
