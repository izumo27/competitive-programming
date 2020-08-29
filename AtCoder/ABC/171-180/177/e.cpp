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

const double EPS=1e-9;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

// 約数を求める
vl divisor(ll n){
  vl res;
  for(ll i=1; i*i<=n; ++i){
    if(n%i==0){
      res.push_back(i);
      if(i!=n/i){
        res.push_back(n/i);
      }
    }
  }
  return res;
}

bool used[1252521];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  ll a[1252521];
  cin>>n;
  REP(i, n){
    cin>>a[i];
  }
  ll allgcd=a[0];
  FOR(i, 1, n){
    allgcd=gcd(allgcd, a[i]);
  }
  bool pair=true;
  REP(i, n){
    vl res=divisor(a[i]);
    for(auto& x : res){
      if(x==1){
        continue;
      }
      if(used[x]){
        pair=false;
        break;
      }
      used[x]=true;
    }
    if(!pair){
      break;
    }
  }
  if(pair && allgcd==1){
    cout<<"pairwise ";
  }
  else if(allgcd==1){
    cout<<"setwise ";
  }
  else{
    cout<<"not ";
  }
  cout<<"coprime"<<'\n';
  return 0;
}
