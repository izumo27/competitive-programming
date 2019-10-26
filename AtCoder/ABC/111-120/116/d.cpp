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

bool used[114514];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  pll dt[114514];
  cin>>n>>k;
  REP(i, n){
    cin>>dt[i].second>>dt[i].first;
  }
  sort(dt, dt+n, greater<pll>());
  ll sum=0, x=0;
  vl q;
  REP(i, k){
    sum+=dt[i].first;
    if(used[dt[i].second]){
      q.push_back(dt[i].first);
    }
    else{
      used[dt[i].second]=true;
      ++x;
    }
  }
  sort(ALL(q));
  ll ans=sum+x*x;
  int idx=0;
  FOR(i, k, n){
    if(x>=k || idx>=q.size()){
      break;
    }
    if(used[dt[i].second]){
      continue;
    }
    used[dt[i].second]=true;
    sum=sum-q[idx++]+dt[i].first;
    ++x;
    CHMAX(ans, sum+x*x);
  }
  cout<<ans<<'\n';
  return 0;
}
