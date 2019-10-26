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

bool used[1<<18];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, s[1<<18];
  cin>>n;
  int m=1<<n;
  REP(i, m){
    cin>>s[i];
  }
  sort(s, s+m);
  set<pii> st;
  REP(i, m-1) st.insert(pii(s[i], i));
  used[m-1]=true;
  REP(_, n){
    vi v;
    FORR(i, 0, m){
      if(!used[i]) continue;
      auto t=st.lower_bound(pii(s[i], -1));
      if(t==st.begin()){
        cout<<"No"<<'\n';
        return 0;
      }
      --t;
      pii x=*(t);
      v.push_back(x.second);
      st.erase(t);
    }
    for(auto &u : v) used[u]=true;
  }
  cout<<"Yes"<<'\n';
  return 0;
}
