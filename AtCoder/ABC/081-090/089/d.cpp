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

int x[92525], y[92525] ,s[92525];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, d, a, q, l, r;
  cin>>h>>w>>d;
  REP(i, h){
    REP(j, w){
      cin>>a;
      x[a]=i;
      y[a]=j;
    }
  }
  FOR(i, d+1, h*w+1){
    s[i]=s[i-d]+abs(x[i-d]-x[i])+abs(y[i-d]-y[i]);
  }
  cin>>q;
  REP(i, q){
    cin>>l>>r;
    cout<<s[r]-s[l]<<'\n';
  }
  return 0;
}
