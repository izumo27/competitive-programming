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

int sh[325252], sw[325252];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int h, w, m;
  cin>>h>>w>>m;
  map<pii, bool> mp;
  REP(i, m){
    int x, y;
    cin>>x>>y;
    --x;--y;
    ++sh[x];
    ++sw[y];
    mp[pii(x, y)]=true;
  }
  vi idh(h);
  iota(ALL(idh), 0);
  sort(ALL(idh), [](int a, int b){
    return sh[a]>sh[b];
  });
  vi th;
  REP(i, h){
    int idx=idh[i];
    if(sh[idx]!=sh[idh[0]]){
      break;
    }
    th.push_back(idx);
  }
  vi idw(w);
  iota(ALL(idw), 0);
  sort(ALL(idw), [](int a, int b){
    return sw[a]>sw[b];
  });
  vi tw;
  REP(i, w){
    int idx=idw[i];
    if(sw[idx]!=sw[idw[0]]){
      break;
    }
    tw.push_back(idx);
  }
  // DEBUG_VEC(th);
  // DEBUG_VEC(tw);
  int ans=sh[th[0]]+sw[tw[0]]-1;
  for(auto& hh : th){
    for(auto& ww : tw){
      bool tmp=mp[pii(hh, ww)];
      if(!tmp){
        ++ans;
        cout<<ans<<'\n';
        return 0;
      }
      CHMAX(ans, sh[hh]+sw[ww]-(mp[pii(hh, ww)] ? 1 : 0));
      // DEBUG(sh[hh]);
      // DEBUG(sw[ww]);
    }
  }
  cout<<ans<<'\n';
  return 0;
}
