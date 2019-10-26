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

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

const int MAX_N=114514;

int prime[MAX_N];
bool is_prime[MAX_N+1];

// エラトステネスの篩
// is_prime[i]=true⇔iが素数
void sieve(int n){
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
}

int s[114514];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q, l, r;
  cin>>q;
  sieve(1e5);
  for(int i=3; i<1e5; i+=2){
    s[i]=s[i-2]+(is_prime[i] && is_prime[(i+1)/2] ? 1 : 0);
  }
  REP(i, q){
    cin>>l>>r;
    cout<<s[r]-s[l-2]<<'\n';
    // DEBUG(s[r]);
    // DEBUG(s[l]);
  }
  return 0;
}
