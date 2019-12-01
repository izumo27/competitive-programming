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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  ll t[2], a[2], b[2];
  cin>>t[0]>>t[1]>>a[0]>>a[1]>>b[0]>>b[1];
  if(a[0]>b[0]){
    swap(a[0], b[0]);
    swap(a[1], b[1]);
  }
  ll c=t[0]*a[0]+t[1]*a[1], d=t[0]*b[0]+t[1]*b[1];
  if(c==d){
    cout<<"infinity"<<'\n';
    return 0;
  }
  if(c<d){
    cout<<0<<'\n';
    return 0;
  }
  ll ans=1;
  ll x=t[0]*b[0]-t[0]*a[0];
  ans+=2*(x/(c-d));
  if(x%(c-d)==0){
    --ans;
  }
  cout<<ans<<'\n';
  return 0;
}