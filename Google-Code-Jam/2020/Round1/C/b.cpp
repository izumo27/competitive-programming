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

int num0[30];
int num[30];
char ans[10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int T;
  cin>>T;
  REP(case_num, T){
    int U;
    cin>>U;
    ll Q[12525];
    string R[12525];
    map<char, int> mp, mp2;
    REP(i, 10000){
      cin>>Q[i]>>R[i];
      ++mp[R[i][0]];
      REP(j, R[i].size()){
        ++mp2[R[i][j]];
      }
    }
    vector<pair<int, char>> v;
    for(auto x : mp2){
      if(mp[x.first]==0){
        ans[0]=x.first;
      }
      else{
        v.emplace_back(mp[x.first], x.first);
      }
    }
    sort(ALL(v));
    int idx=9;
    for(auto x : v){
      ans[idx--]=x.second;
    }
    cout<<"Case #"<<case_num+1<<": ";
    REP(i, 10){
      cout<<ans[i];
    }
    cout<<'\n';
  }
  return 0;
}
