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

string alp="abcdefghijklmnopqrstuvwxyz";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  ll n;
  cin>>n;
  string ans="";
  ll mask=1;
  while(n>0){
    mask*=26;
    ll x=n/mask, y=n%mask;
    ll tmp=y/(mask/26);
    if(tmp==0){
      ans+=alp[26-1];
      n-=mask;
    }
    else{
      ans+=alp[tmp-1];
      n-=y;
    }
    // DEBUG(n);
  }
  int m=ans.size();
  FORR(i, 0, m){
    cout<<ans[i];
  }
  cout<<'\n';
  return 0;
}
