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

int cnt[10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  string s;
  cin>>s;
  int n=s.size();
  REP(i, n){
    ++cnt[s[i]-'0'];
  }
  FOR(i, 1, 1000){
    if(i%8!=0){
      continue;
    }
    int k=i;
    int num[10];
    REP(j, 10){
      num[j]=0;
    }
    int sz=0;
    while(k>0){
      ++num[k%10];
      ++sz;
      k/=10;
    }
    if(sz<3 && sz<n){
      continue;
    }
    bool ok=true;
    REP(j, 10){
      if(num[j]>cnt[j]){
        ok=false;
        break;
      }
    }
    if(ok){
      cout<<"Yes"<<'\n';
      return 0;
    }
  }
  cout<<"No"<<'\n';
  return 0;
}
