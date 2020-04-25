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

constexpr ll INF=1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int t, a, b;
  cin>>t>>a>>b;
  REP(case_num, t){
    string res;
    ll sx=0, sy=0;
    bool center=false;
    [&]{
      for(ll i=-INF/2; i<=INF/2; i+=INF/2){
        for(ll j=-INF/2; j<INF/2; j+=INF/2){
          cout<<i<<' '<<j<<endl;
          cin>>res;
          if(res=="CENTER"){
            center=true;
            return;
          }
          else if(res=="HIT"){
            sx=i;sy=j;
            return;
          }
        }
      }
    }();
    if(center){
      continue;
    }
    ll lx, rx, uy, dy;
    int lv=1;
    ll lb=sx, ub=INF+1;
    ll mid=(lb+ub)/2;
    cout<<mid<<' '<<sy<<endl;
    center=false;
    while(true){
      bool ok=false;
      cin>>res;
      if(res=="CENTER"){
        center=true;
        break;
      }
      else if(res=="HIT"){
        lb=mid;
        mid=(lb+ub)/2;
      }
      else{
        ub=mid;
        mid=(lb+ub)/2;
      }
      if(abs(ub-lb)<=1){
        if(lv==1){
          rx=lb;
          ub=-INF-1;
          lb=sx;
        }
        else if(lv==2){
          lx=lb;
          lb=sy;
          ub=INF+1;
        }
        else if(lv==3){
          uy=lb;
          ub=-INF-1;
          lb=sy;
        }
        else{
          dy=lb;
          ok=true;
        }
        mid=(lb+ub)/2;
        ++lv;
      }
      if(ok){
        break;
      }
      if(lv<=2){
        cout<<mid<<' '<<sy<<endl;
      }
      else{
        cout<<sx<<' '<<mid<<endl;
      }
    }
    if(center){
      continue;
    }
    cout<<(rx+lx)/2<<' '<<(uy+dy)/2<<endl;
    cin>>res;
  }
  return 0;
}
