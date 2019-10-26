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

ll a[60];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll x;
  cin>>n>>x;
  a[0]=1;
  REP(i, n){
    a[i+1]=a[i]*2+3;
  }
  ll ans=0;
  int ind=n;
  bool ok=true;
  while(x>0){
    while(x>0 && a[ind]>x){
      --ind;
      --x;
      if(x==0){
        ok=false;
      }
    }
    if(!ok){
      break;
    }
    if(a[ind]==x){
      ans+=(a[ind]+1)/2;
      break;
    }
    if(a[ind]==x+1){
      ans+=(a[ind]+1)/2+1;
      break;
    }
    ans+=(a[ind]+1)/2+1;
    x-=a[ind]+1;
  }
  cout<<ans<<'\n';
  return 0;
}
