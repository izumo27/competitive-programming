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

int n;
string s;

bool is_ok(int mid){
  vector<pair<string, int>> v;
  REP(i, n-mid+1){
    v.push_back(make_pair(s.substr(i, mid), i));
  }
  sort(ALL(v));
  int i=n-mid;
  bool res=false;
  while(i>0){
    auto x=v[i];
    string t=x.first;
    int u=x.second;
    while(i>=0 && v[i].first==t){
      --i;
    }
    if(i<n-1 && v[i+1].second+mid<=u){
      res=true;
      break;
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>n>>s;
  int lb=0, ub=n;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(is_ok(mid)){
      lb=mid;
    }
    else{
      ub=mid;
    }
  }
  cout<<lb<<'\n';
  return 0;
}
