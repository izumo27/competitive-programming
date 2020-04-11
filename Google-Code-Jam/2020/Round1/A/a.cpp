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

const double EPS=1e-9;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int t;
  cin>>t;
  REP(case_num, t){
    int n;
    cin>>n;
    string p[60];
    string ans="", fir="", lat="";
    vi v;
    REP(i, n){
      cin>>p[i];
      int m=p[i].size();
      string tfir="";
      REP(j, m){
        if(p[i][j]=='*'){
          tfir=p[i].substr(0, j);
          v.push_back(j);
          break;
        }
      }
      string tlat="";
      FORR(j, 0, m){
        if(p[i][j]=='*'){
          tlat=p[i].substr(j+1, m);
          v.push_back(j);
          break;
        }
      }
      if(fir.size()<tfir.size()){
        fir=tfir;
      }
      if(lat.size()<tlat.size()){
        lat=tlat;
      }
    }
    bool ok=true;
    REP(i, n){
      int x=v[i*2], y=v[i*2+1];
      REP(j, x){
        if(p[i][j]!=fir[j]){
          ok=false;
          break;
        }
      }
      int m=p[i].size(), l=lat.size();
      FOR(j, y+1, m){
        if(p[i][j]!=lat[l-(m-j)]){
          ok=false;
          break;
        }
      }
      FOR(j, x, y){
        if(p[i][j]!='*'){
          ans+=p[i][j];
        }
      }
    }
    ans=fir+ans+lat;
    if(!ok){
      ans="*";
    }
    cout<<"Case #"<<case_num+1<<": "<<ans<<'\n';
  }
  return 0;
}
