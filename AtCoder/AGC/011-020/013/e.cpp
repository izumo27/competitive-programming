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

mat mul(mat &a, mat &b){
  int x=a.size(), y=b.size(), z=b[0].size();
  mat c(x, vl(z));
  REP(i, x)REP(k, y)REP(j, z){
    (c[i][j]+=(a[i][k]*b[k][j]%MOD))%=MOD;
  }
  return c;
}

mat power(mat a, ll n){
  int x=a.size();
  mat b(x, vl(x));
  REP(i, x){
    b[i][i]=1;
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
  int n, m;
  ll x[125252];
  cin>>n>>m;
  REP(i, m){
    cin>>x[i+1];
  }
  mat a(3, vl(3));
  a[0][0]=1;a[0][1]=0;a[0][2]=1;
  a[1][0]=2;a[1][1]=1;a[1][2]=2;
  a[2][0]=1;a[2][1]=1;a[2][2]=2;
  mat b(3, vl(3));
  b[0][0]=1;b[0][1]=0;b[0][2]=0;
  b[1][0]=2;b[1][1]=1;b[1][2]=0;
  b[2][0]=1;b[2][1]=1;b[2][2]=1;
  x[0]=0;x[m+1]=n;
  mat c=b;
  REP(i, m+1){
    mat t=power(a, x[i+1]-x[i]-1);
    c=mul(t, c);
    if(i!=m) c=mul(b, c);
  //   REP(j, 3)REP(k, 3) cout<<c[j][k]<<" \n"[k==2];
  //   cout<<"--------------------"<<'\n';
  }
  cout<<c[2][0]<<'\n';
  return 0;
}
