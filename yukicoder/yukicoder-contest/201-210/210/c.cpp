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

// 素因数分解
vector<pii> prime_factor(int n){
  vector<pii> res;
  for(int i=2; i*i<=n; ++i){
    if(n%i!=0){
      continue;
    }
    int num=0;
    while(n%i==0){
      ++num;
      n/=i;
    }
    res.push_back(pii(i, num));
  }
  if(n!=1){
    res.push_back(pii(n, 1));
  }
  return res;
}

int gcd(int a, int b){
  if(b==0){
    return a;
  }
  return gcd(b, a%b);
}

int num[114514];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, k;
  cin>>n>>k;
  int cnt=0, ans=0;
  FOR(i, 1, n){
    vector<pii> v1=prime_factor(gcd(i, n));
    int tmp=0;
    for(auto x : v1){
      tmp+=x.second;
    }
    if(tmp<k){
      continue;
    }
    vector<pii> v2=prime_factor(i);
    tmp=1;
    for(auto x : v2){
      tmp*=x.second+1;
    }
    if(tmp>cnt){
      cnt=tmp;
      ans=i;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
