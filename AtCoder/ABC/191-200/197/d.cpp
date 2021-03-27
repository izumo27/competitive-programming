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

double getRadian(double x, double y, double x2, double y2) {
  double radian = atan2(y2 - y,x2 - x);
  return radian;
}

static const double pi = 3.141592653589793;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(10)<<fixed;
  int n, a, b, c, d;
  cin>>n>>a>>b>>c>>d;
  double x=(double)(a+c)/2, y=(double)(b+d)/2;
  double r=sqrt((x-a)*(x-a)+(y-b)*(y-b));
  double theta=getRadian(x, y, a, b);
  double xx=x+r*cos(theta+2*pi/n), yy=y+r*sin(theta+2*pi/n);
  cout<<xx<<' '<<yy<<'\n';
  return 0;
}
