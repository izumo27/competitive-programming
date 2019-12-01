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

#define DEBUG(x) cout<<#x<<": "<<(x)<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

constexpr ll MOD=1000000007ll;
// constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  string s;
  ll a[2525], Q, b[2525];
  cin>>n>>s;
  REP(i, n){
    cin>>a[i];
    b[i]=a[i];
  }
  string t=s;
  reverse(ALL(t));
  reverse(b, b+n);
  cin>>Q;
  while(Q--){
    ll k;
    cin>>k;
    int ans=0;
    {
      int r=0, cnt=0;
      ll sum=0;
      REP(l, n){
        while((r<=l) || (r<n && sum+a[r]<=k)){
          sum+=a[r];
          if(s[r]=='E'){
            ++cnt;
          }
          ++r;
        }
        if(sum<=k){
          CHMAX(ans, cnt);
        }
        if(s[l]=='E'){
          --cnt;
        }
        sum-=a[l];
      }
    }
    {
      int r=0, cnt=0;
      ll sum=0;
      REP(l, n){
        while((r<=l) || (r<n && sum+b[r]<=k)){
          sum+=b[r];
          if(t[r]=='E'){
            ++cnt;
          }
          ++r;
        }
        if(sum<=k){
          CHMAX(ans, cnt);
        }
        if(t[l]=='E'){
          --cnt;
        }
        sum-=b[l];
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}