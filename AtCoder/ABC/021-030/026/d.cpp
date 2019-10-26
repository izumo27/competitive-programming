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

const double EPS=1e-7;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

const double pi = 3.14159265358979;

double a, b, c;

double f(double t){
  return a*t+b*sin(c*t*pi);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  scanf("%lf%lf%lf", &a, &b, &c);
  double lb=0.0, ub=201.0;
  while(abs(f(ub)-100.0)>EPS){
    double mid=(lb+ub)/2.0;
    if(f(mid)>100.0){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }
  printf("%.10lf\n", ub);
  return 0;
}
