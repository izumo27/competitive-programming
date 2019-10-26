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

int gcd(int a, int b){
  if(b==0){
    return a;
  }
  return gcd(b, a%b);
}

int lcm(int a, int b){
  return a/gcd(a, b)*b;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  string s, t;
  cin>>n>>m>>s>>t;
  if(s[0]!=t[0]){
    cout<<-1<<'\n';
    return 0;
  }
  if(n==m){
    cout<<(s==t ? n : -1)<<'\n';
    return 0;
  }
  int a=gcd(n, m);
  int b=n/a, c=m/a;
  bool ok=true;
  int j=c;
  for(int i=b; i<n; i+=b){
    if(j>=m){
      break;
    }
    if(s[i]!=t[j]){
      ok=false;
    }
    j+=c;
  }
  ll nn=n, mm=m, aa=a;
  cout<<(ok ? nn/aa*mm : -1)<<'\n';
  return 0;
}
