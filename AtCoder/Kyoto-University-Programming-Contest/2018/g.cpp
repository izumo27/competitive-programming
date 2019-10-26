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

const int MAX_N=364364;

int prime[MAX_N];
bool is_prime[MAX_N+1];
int Exp[MAX_N+1];

ll a[364364], b[364364];
bool d[364364];

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
  int n, m, c;
  cin>>n>>m;
  REP(i, m){
    cin>>c;
    d[c]=true;
  }
  int res=sieve(n);
  REP(i, res){
    int pr=prime[i];
    int j=pr;
    while(true){
      Exp[j]=pr;
      ll tmp1=j, tmp2=pr, tmp3=n;
      if(tmp1*tmp2>tmp3){
        break;
      }
      j*=pr;
    }
  }
  FOR(i, 2, n+1){
    if(Exp[i]==0){
      continue;
    }
    if(d[i]){
      cout<<"No"<<'\n';
      return 0;
    }
    a[i]=1e10*log(Exp[i]);
  }
  cout<<"Yes"<<'\n';
  FOR(i, 1, n+1){
    cout<<a[i]<<" \n"[i==n];
  }
  return 0;
}
