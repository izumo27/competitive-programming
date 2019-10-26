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
  int n, q, k;
  string s;
  cin>>n>>s>>q;
  REP(i, q){
    cin>>k;
    int sumd=0, summ=0;
    ll ans=0, sum=0;
    REP(j, k){
      if(s[j]=='D'){
        ++sumd;
      }
      else if(s[j]=='M'){
        ++summ;
        sum+=sumd;
      }
      else if(s[j]=='C'){
        ans+=sum;
      }
    }
    FOR(j, k, n){
      if(s[j-k]=='D'){
        --sumd;
        sum-=summ;
      }
      else if(s[j-k]=='M'){
        --summ;
      }
      if(s[j]=='D'){
        ++sumd;
      }
      else if(s[j]=='M'){
        ++summ;
        sum+=sumd;
      }
      else if(s[j]=='C'){
        ans+=sum;
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}
