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
  int a, b, c;
  cin>>a>>b>>c;
  if(a&1 || b&1 || c&1){
    cout<<0<<'\n';
    return 0;
  }
  if(a==b && b==c){
    cout<<-1<<'\n';
    return 0;
  }
  int cnt=0;
  while((a&1)==0 && (b&1)==0 && (c&1)==0){
    int aa=a, bb=b, cc=c;
    a=bb/2+cc/2;
    b=aa/2+cc/2;
    c=aa/2+bb/2;
    ++cnt;
  }
  cout<<cnt<<'\n';
  return 0;
}
