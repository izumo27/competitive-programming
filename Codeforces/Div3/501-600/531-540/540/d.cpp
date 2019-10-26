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

ll n, m;
ll a[252521];
ll sum[252521];

bool is_ok(ll mid){
  if(n<=mid){
    return true;
  }
  vl v[mid];
  REP(i, n){
    v[i%mid].push_back(a[i]);
  }
  ll cnt=0;
  REP(i, mid){
    REP(j, v[i].size()){
      cnt+=max(0ll, v[i][j]-j);
    }
  }
  // if(mid==2){
  //   DEBUG(cnt);
  // }
  return cnt>=m;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  REP(i, n){
    cin>>a[i];
  }
  sort(a, a+n, greater<ll>());
  REP(i, n){
    sum[i+1]=sum[i]+a[i];
  }
  if(sum[n]<m){
    cout<<-1<<'\n';
    return 0;
  }
  ll lb=0, ub=1e10;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(is_ok(mid)){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }
  cout<<ub<<'\n';
  return 0;
}
