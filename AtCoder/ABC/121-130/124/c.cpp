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

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  string s;
  cin>>s;
  int n=s.size();
  int cnt1=0;
  REP(i, n){
    if(i&1){
      if(s[i]!='0'){
        ++cnt1;
      }
    }
    else{
      if(s[i]!='1'){
        ++cnt1;
      }
    }
  }
  int cnt2=0;
  REP(i, n){
    if(i&1){
      if(s[i]!='1'){
        ++cnt2;
      }
    }
    else{
      if(s[i]!='0'){
        ++cnt2;
      }
    }
  }
  cout<<min(cnt1, cnt2)<<'\n';
  return 0;
}
