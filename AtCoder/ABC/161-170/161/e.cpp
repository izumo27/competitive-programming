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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, k, c;
  cin>>n>>k>>c;
  string s;
  cin>>s;
  vi cnd;
  int cur;
  REP(i, n){
    if(s[i]=='o'){
      cnd.push_back(i);
      cur=i+c+1;
      break;
    }
  }
  int cnt=0;
  while(cur<n){
    while(cur<n && s[cur]=='x'){
      ++cur;
    }
    if(cur<n){
      cnd.push_back(cur);
      cur+=c+1;
      ++cnt;
      if(cnt>=k){
        break;
      }
    }
  }
  vi cndd;
  FORR(i, 0, n){
    if(s[i]=='o'){
      cndd.push_back(i);
      cur=i-(c+1);
      break;
    }
  }
  cnt=0;
  while(cur>=0){
    while(cur>=0 && s[cur]=='x'){
      --cur;
    }
    if(cur>=0){
      cndd.push_back(cur);
      // DEBUG(cur);
      cur-=c+1;
      ++cnt;
    }
  }
  // DEBUG_VEC(cnd);
  // DEBUG_VEC(cndd);
  REP(i, k){
    if(cnd[i]==cndd[k-1-i]){
      cout<<cnd[i]+1<<'\n';
    }
  }
  return 0;
}
