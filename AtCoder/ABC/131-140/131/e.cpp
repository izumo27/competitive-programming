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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, k;
  cin>>n>>k;
  if(n*(n-1)/2-k<n-1){
    cout<<-1<<'\n';
    return 0;
  }
  vector<pii> ans;
  REP(i, n-1){
    ans.push_back(pii(0, i+1));
  }
  int num=(n-1)*(n-2)/2;
  int idx1=n-2, idx2=n-1;
  while(num!=k){
    ans.push_back(pii(idx1, idx2));
    --num;
    if(idx1==1){
      --idx2;
      idx1=idx2-1;
    }
    else{
      --idx1;
    }
  }
  cout<<(int)ans.size()<<'\n';
  for(auto x : ans){
    cout<<x.first+1<<' '<<x.second+1<<'\n';
  }
  return 0;
}
