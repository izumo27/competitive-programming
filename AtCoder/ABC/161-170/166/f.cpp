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

char ans[125252];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  ll a, b, c;
  string s[125252];
  cin>>n>>a>>b>>c;
  REP(i, n){
    cin>>s[i];
  }
  ll x[3];
  x[0]=a;x[1]=b;x[2]=c;
  REP(i, n){
    int c1=s[i][0]-'A', c2=s[i][1]-'A';
    if(x[c1]<x[c2]){
      ans[i]=s[i][0];
      ++x[c1];--x[c2];
    }
    else if(x[c1]>x[c2]){
      ans[i]=s[i][1];
      --x[c1];++x[c2];
    }
    else{
      int n1=-1, n2=-1;
      if(i<n-1){
        n1=s[i+1][0]-'A';n2=s[i+1][1]-'A';
      }
      if(c1==n1 || c1==n2){
        // DEBUG(c1);
        ans[i]=s[i][0];
        ++x[c1];--x[c2];
      }
      else{
        ans[i]=s[i][1];
        --x[c1];++x[c2];
      }
    }
    if(x[c1]<0 || x[c2]<0){
      cout<<"No"<<'\n';
      return 0;
    }
  }
  cout<<"Yes"<<'\n';
  REP(i, n){
    cout<<ans[i]<<'\n';
  }
  return 0;
}
