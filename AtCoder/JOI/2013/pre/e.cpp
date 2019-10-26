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

int n, K;
ll X1[60], Y1[60], D1[60], X2[60], Y2[60], D2[60];
int fld[100][100][100];

vl compress(ll *x1, ll *x2){
  vl xs;
  REP(i, n){
    xs.push_back(x1[i]);
    xs.push_back(x2[i]);
  }
  sort(ALL(xs));
  xs.erase(unique(ALL(xs)), xs.end());
  REP(i, n){
    x1[i]=find(ALL(xs), x1[i])-xs.begin();
    x2[i]=find(ALL(xs), x2[i])-xs.begin();
  }
  return xs;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>K;
  REP(i, n){
    cin>>X1[i]>>Y1[i]>>D1[i]>>X2[i]>>Y2[i]>>D2[i];
  }
  vl X=compress(X1, X2);
  vl Y=compress(Y1, Y2);
  vl D=compress(D1, D2);
  REP(i, n){
    FOR(x, X1[i], X2[i]){
      FOR(y, Y1[i], Y2[i]){
        FOR(d, D1[i], D2[i]){
          ++fld[x][y][d];
        }
      }
    }
  }
  ll ans=0;
  REP(i, X.size()-1){
    REP(j, Y.size()-1){
      REP(k, D.size()-1){
        if(fld[i][j][k]>=K){
          ans+=(X[i+1]-X[i])*(Y[j+1]-Y[j])*(D[k+1]-D[k]);
        }
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
