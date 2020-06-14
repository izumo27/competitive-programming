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

constexpr int INF=1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, q, a[252521], b[252521];
  multiset<int> ms[252521];
  cin>>n>>q;
  REP(i, n){
    cin>>a[i]>>b[i];
    --b[i];
    ms[b[i]].insert(a[i]);
  }
  multiset<int> s;
  REP(i, 252521){
    if(ms[i].size()){
      s.insert(*(ms[i].rbegin()));
    }
  }
  int ans=*(s.begin());
  REP(i, q){
    int c, d;
    cin>>c>>d;
    --c;--d;
    {
      int old=b[c];
      ms[old].erase(ms[old].find(a[c]));
      if(ms[old].size()){
        int tmp=*(--ms[old].end());
        if(tmp<a[c]){
          s.erase(s.find(a[c]));
          s.insert(tmp);
        }
      }
      else{
        s.erase(s.find(a[c]));
      }
    }
    {
      int old=b[c];
      if(ms[d].size()){
        int tmp=*(ms[d].rbegin());
        if(tmp<a[c]){
          s.erase(s.find(tmp));
          s.insert(a[c]);
        }
        ms[d].insert(a[c]);
      }
      else{
        ms[d].insert(a[c]);
        s.insert(a[c]);
      }
      b[c]=d;
    }
    ans=*(s.begin());
    // for(auto x : s){
    //   cout<<x<<' ';
    // }
    // cout<<'\n';
    cout<<ans<<'\n';
  }
  return 0;
}
