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

#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

#define CHMIN(a, b) a=min((a), (b))
#define CHMAX(a, b) a=max((a), (b))

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, l, t[114514], x, a[114514], y, b;
  cin>>n>>m>>l;
  REP(i, n){
    cin>>t[i];
  }
  vi aa[114514];
  REP(i, m){
    cin>>x>>a[i];
    aa[x-1].push_back(a[i]);
  }
  vi bb[114514];
  REP(i, l){
    cin>>y>>b;
    bb[y-1].push_back(b);
  }
  vector<pii> v;
  REP(i, n){
    if(aa[i].empty() || bb[i].empty()){
      continue;
    }
    sort(ALL(aa[i]));
    sort(ALL(bb[i]));
    REP(j, bb[i].size()){
      int tmp=bb[i][j];
      auto itr=lower_bound(ALL(aa[i]), tmp-t[i]);
      // DEBUG(*itr);
      if(itr!=aa[i].begin()){
        v.push_back(pii(tmp+t[i]+1, *(itr-1)));
      }
    }
  }
  int ans=0, now=0;
  sort(ALL(v));
  REP(i, v.size()){
    if(v[i].second>=now){
      ans+=2;
      now=v[i].first;
    }
  }
  REP(i, m){
    if(a[i]>=now){
      ++ans;
      break;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
