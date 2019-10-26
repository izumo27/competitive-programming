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

ll comb[60][60];

void COMinit(int n){
  REP(i, n+1){
    REP(j, i+1){
      if(j==0 || j==i){
        comb[i][j]=1;
      }
      else{
        comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  ll v[60];
  cin>>n>>a>>b;
  REP(i, n){
    cin>>v[i];
  }
  sort(v, v+n, greater<ll>());
  double sum=0.0;
  int c=0;
  REP(i, a){
    sum+=v[i];
    if(i>0 && v[i-1]!=v[i]){
      c=i;
    }
  }
  COMinit(n);
  ll ans=0;
  ll d=upper_bound(v, v+n, v[a-1], greater<ll>())-lower_bound(v, v+n, v[a-1], greater<ll>());
  if(c!=0){
    ans=comb[d][a-c];
  }
  else{
    FOR(i, a, b+1){
      ans+=comb[d][i];
    }
  }

  cout.precision(10);
  cout<<fixed<<sum/a<<'\n';
  cout<<ans<<'\n';
  return 0;
}
