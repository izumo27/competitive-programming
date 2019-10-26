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

typedef vector<vl> mat;
ll one=(1ll<<32)-1;

mat mul(mat &a, mat &b){
  int x=a.size(), y=b.size(), z=b[0].size();
  mat c(x, vl(z));
  REP(i, x)REP(k, y)REP(j, z){
    c[i][j]^=(a[i][k]&b[k][j]);
  }
  return c;
}

mat power(mat a, int n){
  int x=a.size();
  mat b(x, vl(x));
  REP(i, x){
    b[i][i]=one;
  }
  while(n>0){
    if(n&1){
      b=mul(b, a);
    }
    a=mul(a, a);
    n>>=1;
  }
  return b;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int k, m;
  cin>>k>>m;
  ll a[125];
  mat A(k, vl(k));
  REP(i, k){
    cin>>a[i];
  }
  REP(i, k){
    cin>>A[0][i];
  }
  REP(i, k-1){
    A[i+1][i]=one;
  }
  if(m<=k){
    cout<<a[m-1]<<'\n';
    return 0;
  }
  A=power(A, m-k);
  // REP(i, 3)REP(j, 3){
  //   cout<<A[i][j]<<" \n"[j==2];
  // }
  ll ans=0;
  REP(i, k){
    ans^=(A[0][i]&a[k-1-i]);
  }
  cout<<ans<<'\n';
  return 0;
}
