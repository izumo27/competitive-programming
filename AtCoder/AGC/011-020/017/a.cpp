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

ll power(ll a, ll b){
  ll res=1;
  while(b>0){
    if(b&1){
      res=res*a;
    }
    a=a*a;
    b>>=1;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p, a;
  cin>>n>>p;
  bool odd=false;
  REP(i, n){
    cin>>a;
    if(a&1){
      odd=true;
    }
  }
  cout<<(odd ? power(2, n-1) : (p ? 0 : power(2, n)))<<'\n';
  return 0;
}
