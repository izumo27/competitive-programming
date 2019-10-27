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

static const double pi = 3.141592653589793;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(10)<<fixed;
	double a, b, x;
  cin>>a>>b>>x;
  if(a*a*b==x){
    cout<<0<<'\n';
    return 0;
  }
  if(a*a*b/2<x){
    double lb=0, ub=90;
    while(ub-lb>1e-9){
       double mid=(lb+ub)/2;
      if(a*a*b-0.5*a*a/tan(pi/180*mid)*a>x){
        ub=mid;
      }
      else{
        lb=mid;
      }
    }
    cout<<90-ub<<'\n';
  }
  else{
    double lb=0, ub=90;
    while(ub-lb>1e-9){
      double mid=(lb+ub)/2;
      if(0.5*b*b*tan(pi/180*mid)*a>x){
        ub=mid;
      }
      else{
        lb=mid;
      }
    }
    cout<<90-ub<<'\n';
  }
	return 0;
}
