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

int n, a[3], b[3];

ll calc(ll k, int idx, bool flag){
  if(flag){
    return k/a[idx]*b[idx]+k%a[idx];
  }
  return k/b[idx]*a[idx]+k%b[idx];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>n;
  REP(i, 3){
    cin>>a[i];
  }
  REP(i, 3){
    cin>>b[i];
  }
  int c[3];
  int cnt=0;
  vi pls, mns;
  REP(i, 3){
    c[i]=b[i]-a[i];
    if(c[i]>=0){
      ++cnt;
      pls.push_back(i);
    }
    else{
      mns.push_back(i);
    }
  }
  ll ans=n;
  if(cnt==1){
    ans=calc(n, pls[0], 1);
    ll tmp=ans;
    REP(i, tmp+1){
      CHMAX(ans, calc(i, mns[0], 0)+calc(tmp-i, mns[1], 0));
    }
  }
  else if(cnt==2){
    REP(i, n+1){
      CHMAX(ans, calc(i, pls[0], 1)+calc(n-i, pls[1], 1));
    }
    ans=calc(ans, mns[0], 0);
  }
  else{
    if(cnt==0){
      swap(a, b);
    }
    REP(i, n+1){
      ll tmp=calc(i, 0, 1);
      REP(j, n-i+1){
        CHMAX(ans, tmp+calc(j, 1, 1)+calc(n-i-j, 2, 1));
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
