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

ll s[252525];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a[252525];
  cin>>n;
  REP(i, n){
    cin>>a[i];
    s[i+1]=s[i]+a[i];
  }
  int l=0, r=2;
  ll ans=s[n];
  FOR(i, 1, n-2){
    ll bc=s[i+1];
    ll de=s[n]-s[i+1];
    ll b=s[l+1];
    ll d=s[r+1]-s[i+1];
    while(b*2<bc){
      ++l;
      b+=a[l];
    }
    ll tmpb=b-a[l];
    if(abs(bc-2*b)>abs(bc-2*tmpb) && l-1>=0 && l-1<i){
      --l;
      b=tmpb;
    }
    while(d*2<de){
      ++r;
      d+=a[r];
    }
    ll tmpd=d-a[r];
    if(abs(de-2*d)>abs(de-2*tmpd) && r-1>i){
      --r;
      d=tmpd;
    }
    ans=min(ans, (max({b, bc-b, d, de-d})-min({b, bc-b, d, de-d})));
    // DEBUG(b);
    // DEBUG(bc-b);
    // DEBUG(d);
    // DEBUG(de-d);
  }
  cout<<ans<<'\n';
  return 0;
}
