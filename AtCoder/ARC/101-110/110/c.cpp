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

// constexpr ll MOD=1000000007ll;
constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

constexpr int INF=1e9;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, p[252521];
  cin>>n;
  queue<pii> que;
  REP(i, n){
    cin>>p[i];
    --p[i];
    if(p[i]==i){
      cout<<-1<<'\n';
      return 0;
    }
    if(p[i]>i){
      que.push(pii(p[i], i));
    }
    else{
      que.push(pii(p[i], i-1));
    }
  }
  int used[252521];
  REP(i, n-1){
    used[i]=INF;
  }
  bool ok=true;
  vi ans;
  while(!que.empty()){
    auto [pp, x]=que.front();que.pop();
    // DEBUG(pp);
    // DEBUG(x);
    if(used[x]==INF){
      used[x]=-1;
      continue;
    }
    if(used[x]!=-1){
      ok=false;
      break;
    }
    ans.push_back(x);
    used[x]=pp;
    swap(p[x], p[x+1]);
    REP(i, 2){
      if(p[x+i]>x+i){
        que.push(pii(p[x+i], x+i));
      }
      if(p[x+i]<x+i){
        que.push(pii(p[x+i], x+i-1));
      }
    }
  }
  REP(i, n-1){
    if(used[i]==INF || used[i]==-1){
      ok=false;
      break;
    }
  }
  if(!ok){
    cout<<-1<<'\n';
    return 0;
  }
  for(auto& x : ans){
    cout<<x+1<<'\n';
  }
  return 0;
}
