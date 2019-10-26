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

constexpr int INF=1e9;
int cnt[125252];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[125252];
  vi b;
  cin>>n;
  REP(i, n){
    cin>>a[i];
    b.push_back(a[i]);
  }
  sort(ALL(b));
  b.erase(unique(ALL(b)), b.end());
  REP(i, n){
    a[i]=lower_bound(ALL(b), a[i])-b.begin();
  }
  set<int> cnd;
  cnd.insert(a[n-1]);
  ++cnt[a[n-1]];
  int ans=1;
  FORR(i, 0, n-1){
    auto itr=cnd.upper_bound(a[i]);
    //int tmp=itr-cnd.begin();
    if(itr==cnd.end()){
      ++ans;
      cnd.insert(a[i]);
      ++cnt[a[i]];
    }
    else{
      int num=cnt[*itr];
      if(num==1){
        --cnt[*itr];
        cnd.erase(*itr);
        cnd.insert(a[i]);
        ++cnt[a[i]];
      }
      else{
        --cnt[*itr];
        cnd.insert(a[i]);
        ++cnt[a[i]];
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
