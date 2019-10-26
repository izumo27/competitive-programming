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
  int n, m;
  ll a[114514];
  cin>>n>>m;
  ll sum[114514];
  sum[0]=0;
  REP(i, n){
    cin>>a[i];
    sum[i+1]=(sum[i]+a[i])%m;
  }
  sort(sum, sum+n+1);
  ll cnt=1;
  ll ans=0;
  REP(i, n){
    if(sum[i+1]==sum[i]){
      ++cnt;
    }
    else{
      ans+=cnt*(cnt-1)/2;
      cnt=1;
    }
  }
  ans+=cnt*(cnt-1)/2;
  cout<<ans<<'\n';
  return 0;
}
