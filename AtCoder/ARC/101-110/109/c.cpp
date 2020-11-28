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

// constexpr ll MOD=1000000007ll;
constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, k;
  string s;
  cin>>n>>k>>s;
  if(n==1){
    cout<<s[0]<<'\n';
    return 0;
  }
  int beki=1;
  while(beki<=n){
    beki*=2;
  }
  beki/=2;
  // DEBUG(beki);
  while(k>0){
    int cur=0;
    string t="";
    int ma_cnt=0;
    REP(j, n){
      rotate(s.begin(), s.begin()+cur, s.end());
      string bfr=s.substr(0, beki);
      // DEBUG(bfr);
      int cnt=0;
      while(bfr.size()>1 && cnt<k){
        string nxt="";
        for(int l=0; l<bfr.size(); l+=2){
          if(bfr[l]==bfr[l+1]){
            nxt+=bfr[l];
            continue;
          }
          if(bfr[l]=='R'){
            nxt+=(bfr[l+1]=='P' ? 'P' : 'R');
          }
          if(bfr[l]=='P'){
            nxt+=(bfr[l+1]=='R' ? 'P' : 'S');
          }
          if(bfr[l]=='S'){
            nxt+=(bfr[l+1]=='R' ? 'R' : 'S');
          }
        }
        bfr=nxt;
        ++cnt;
      }
      t+=bfr[0];
      rotate(s.begin(), s.begin()+(n-cur), s.end());
      cur=(cur+beki)%n;
      ma_cnt=cnt;
    }
    s=t;
    k-=ma_cnt;
    // DEBUG(s);
  }
  std::cout<<s[0]<<'\n';
  return 0;
}
