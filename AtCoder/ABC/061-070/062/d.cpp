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

ll ma[114514], mb[114514];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a[364364];
  cin>>n;
  priority_queue<int, vector<int>, greater<int>> pqa;
  priority_queue<int> pqb;
  REP(i, n*3){
    cin>>a[i];
    if(i<n){
      pqa.push(a[i]);
      ma[0]+=a[i];
    }
    if(i>=n*2){
      pqb.push(a[i]);
      mb[n]+=a[i];
    }
  }
  FOR(i, n, n*2){
    pqa.push(a[i]);
    ma[i-n+1]=ma[i-n]+a[i]-pqa.top();
    pqa.pop();
  }
  FORR(i, n, n*2){
    pqb.push(a[i]);
    mb[i-n]=mb[i-n+1]+a[i]-pqb.top();
    pqb.pop();
  }
  ll ans=-1e18;
  REP(i, n+1){
    ans=max(ans, ma[i]-mb[i]);
    // DEBUG(ma[i]);
    // DEBUG(mb[i]);
  }
  cout<<ans<<'\n';
  return 0;
}
