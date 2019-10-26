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
  int n;
  ll a[114514], b[114514], ab[214514];
  pair<ll, int> aa[114514], bb[114514];
  cin>>n;
  REP(i, n){
    cin>>a[i]>>b[i];
    ab[i]=a[i];
    ab[n+i]=b[i];
    aa[i]=make_pair(a[i], i);
    bb[i]=make_pair(b[i], i);
  }
  sort(ab, ab+n*2);
  sort(aa, aa+n);
  sort(bb, bb+n);
  ll ans=0, sum1=0, sum2=0;
  REP(i, n){
    ans+=ab[i];
    sum1+=a[i];
    sum2+=b[i];
  }
  if(sum1!=ans && sum2!=ans){
    bool ok=false;
    REP(i, n){
      if((a[i]<ab[n-1] && b[i]<ab[n-1]) || (a[i]==ab[n-1] && b[i]==ab[n-1] && ab[n-2]==ab[n-1])){
        ok=true;
        break;
      }
    }
    if(!ok){
      ll tmp=ans;
      ans=1e18;
      REP(i, n){
        if(aa[i].first>ab[n-1]){
          break;
        }
        if(b[aa[i].second]!=ab[n]){
          ans=min(ans, tmp-aa[i].first+ab[n]);
        }
        else{
          ans=min(ans, tmp-aa[i].first+ab[n+1]);
        }
      }
      REP(i, n){
        if(bb[i].first>ab[n-1]){
          break;
        }
        if(a[bb[i].second]!=ab[n]){
          ans=min(ans, tmp-bb[i].first+ab[n]);
        }
        else{
          ans=min(ans, tmp-bb[i].first+ab[n+1]);
        }
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
