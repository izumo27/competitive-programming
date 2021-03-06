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

template<typename T> T gcd(T a, T b){
  if(b==0){
    return a;
  }
  return gcd(b, a%b);
}

template<typename T> T lcm(T a, T b){
  return a/gcd(a, b)*b;
}

template<typename T> T extgcd(T a, T b, T& x, T& y){
  T d=a;
  if(b>0){
    d=extgcd(b, a%b, y, x);
    y-=a/b*x;
  }
  else{
    x=1;
    y=0;
  }
  return d;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}
