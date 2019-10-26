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

ll sx, sy, gx, gy, n;
ll nx[114514], ny[114514];
string s;

bool is_ok(ll a){
  ll x=(a/n)*nx[n]+nx[a%n], y=(a/n)*ny[n]+ny[a%n];
  return abs(sx+x-gx)+abs(sy+y-gy)<=a;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>sx>>sy>>gx>>gy>>n>>s;
  REP(i, n){
    nx[i+1]=nx[i];
    ny[i+1]=ny[i];
    if(s[i]=='U'){
      ++ny[i+1];
    }
    if(s[i]=='D'){
      --ny[i+1];
    }
    if(s[i]=='L'){
      --nx[i+1];
    }
    if(s[i]=='R'){
      ++nx[i+1];
    }
  }
  ll lb=-1, ub=1e17;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(is_ok(mid)){
      ub=mid;
    }
    else{
      lb=mid;
    }
  }
  if(ub==(ll)1e17){
    cout<<-1<<'\n';
  }
  else{
    cout<<ub<<'\n';
  }
  return 0;
}
