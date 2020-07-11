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
  int T;
  cin>>T;
  while(T--){
    int n, k, l, r;
    cin>>n;
    vector<pii> a, b;
    ll ans=0;
    REP(i, n){
      cin>>k>>l>>r;
      ans+=min(l, r);
      if(l>r){
        a.push_back(pii(k, l-r));
      }
      if(l<r){
        b.push_back(pii(n-k, r-l));
      }
    }
    sort(ALL(a));
    sort(ALL(b));
    priority_queue<int, vi, greater<int>> pq;
    for(auto xy : a){
      int x=xy.first, y=xy.second;
      ans+=y;
      pq.push(y);
      if(pq.size()>x){
        ans-=pq.top();
        pq.pop();
      }
    }
    priority_queue<int, vi, greater<int>> pq2;
    for(auto xy : b){
      int x=xy.first, y=xy.second;
      ans+=y;
      pq2.push(y);
      if(pq2.size()>x){
        ans-=pq2.top();
        pq2.pop();
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}
