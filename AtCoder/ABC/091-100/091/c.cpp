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
#define CHMAX(a, b) a=min((a), (b))

const int MOD=1000000007;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

bool used[113];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b, c, d;
  pii ab[114], cd[114];
  cin>>n;
  REP(i, n){
    cin>>a>>b;
    ab[i]=pii(a, b);
  }
  REP(i, n){
    cin>>c>>d;
    cd[i]=pii(c, d);
  }
  sort(ab, ab+n);
  sort(cd, cd+n);
  REP(i, n){
    int cd1=cd[i].first, cd2=cd[i].second;
    int cnt=0;
    int cnt2=110;
    int y=-1;
    while(cd1>ab[cnt].first && cnt<n){
      if(y<ab[cnt].second  && cd2>ab[cnt].second && used[cnt]==false){
        y=ab[cnt].second;
        cnt2=cnt;
      }
      ++cnt;
    }
    used[cnt2]=true;
    // DEBUG(cnt);
    // DEBUG(cnt2);
  }
  int ans=0;
  REP(i, n){
    if(used[i]) ++ans;
  }
  cout<<ans<<'\n';
  return 0;
}
