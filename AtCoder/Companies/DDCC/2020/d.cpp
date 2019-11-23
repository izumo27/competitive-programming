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

ll ans;
vl res;

ll f(ll c, int d, ll x, ll y){
  while(c>0 && c/x){
    ans+=c/x*y;
    c-=c/x*(x-1);
  }
  REP(_, c){
    res.push_back(d);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int m, d[252521];
  ll c[252521];
  cin>>m;
  REP(i, m){
    cin>>d[i]>>c[i];
  }
  REP(i, m){
    if(d[i]==0){
      ans+=c[i];
    }
    if(d[i]==1){
      f(c[i], d[i], 10, 10);
    }
    if(d[i]==2){
      f(c[i], d[i], 10, 11);
    }
    if(d[i]==3){
      f(c[i], d[i], 4, 4);
    }
    if(d[i]==4){
      f(c[i], d[i], 10, 13);
    }
    if(d[i]==5){
      f(c[i], d[i], 10, 14);
    }
    if(d[i]==6){
      f(c[i], d[i], 4, 5);
    }
    if(d[i]==7){
      f(c[i], d[i], 10, 16);
    }
    if(d[i]==8){
      f(c[i], d[i], 10, 17);
    }
    if(d[i]==9){
      f(c[i], d[i], 2, 2);
    }
  }
  int n=res.size();
  REP(i, n-1){
    ++ans;
    res[i+1]+=res[i];
    if(res[i+1]>=10){
      ++ans;
      res[i+1]=res[i+1]%10+1;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
