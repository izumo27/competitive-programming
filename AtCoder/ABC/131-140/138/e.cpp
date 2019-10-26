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

int num1[30];
int num2[30];
constexpr int INF=1e9;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  string s, t;
  cin>>s>>t;
  int n=s.size(), m=t.size();
  vi a[30];
  REP(i, n){
    ++num1[s[i]-'a'];
    a[s[i]-'a'].push_back(i+1);
  }
  REP(i, m){
    ++num2[t[i]-'a'];
  }
  REP(i, 30){
    if(num1[i]==0 && num2[i]>0){
      cout<<-1<<'\n';
      return 0;
    }
  }
  REP(i, 30){
    a[i].push_back(INF);
  }
  ll ans=0;
  int crt=0;
  REP(i, m){
    int tmp1=*upper_bound(ALL(a[t[i]-'a']), crt);
    int tmp2=*upper_bound(ALL(a[t[i]-'a']), 0);
    // DEBUG(tmp1);
    // DEBUG(tmp2);
    if(tmp1==INF){
      ans+=n-crt+tmp2;
      crt=tmp2;
    }
    else{
      ans+=tmp1-crt;
      crt=tmp1;
    }
    // DEBUG(ans);
  }
  cout<<ans<<'\n';
  return 0;
}
