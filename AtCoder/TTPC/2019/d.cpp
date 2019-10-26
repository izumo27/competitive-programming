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

constexpr int MAX_N=1252525;

int prime[MAX_N];
bool is_prime[MAX_N+1];

// エラトステネスの篩
// is_prime[i]=true⇔iが素数
int sieve(int n){
  int res=0;
  REP(i, n+1){
    is_prime[i]=true;
  }
  is_prime[0]=is_prime[1]=false;
  FOR(i, 2, n+1){
    if(is_prime[i]){
      prime[res++]=i;
      for(int j=2*i; j<=n; j+=i){
        is_prime[j]=false;
      }
    }
  }
  return res;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, X;
  cin>>n;
  sieve(MAX_N);
  int ans=0;
  REP(i, n){
    cin>>X;
    if(X==7){
      ans^=3;
      continue;
    }
    if(is_prime[X-2]){
      ans^=2;
    }
    else{
      ans^=1;
    }
  }
  cout<<(ans ? "An" : "Ai")<<'\n';
  return 0;
}
