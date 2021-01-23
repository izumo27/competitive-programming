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

ll fugo[252521][2];
ll hanten[252521];
ll cnt[252521][2];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, m, q, a[252521], b[252521];
  ll x[252521], y[252521];
  cin>>n;
  REP(i, n){
    cin>>x[i]>>y[i];
  }
  cin>>m;
  fugo[0][0]=fugo[0][1]=1;
  REP(i, m){
    int op;
    cin>>op;
    if(op==1){
      fugo[i+1][0]=fugo[i][1];
      fugo[i+1][1]=-fugo[i][0];
      hanten[i+1]=hanten[i]+1;
      cnt[i+1][0]=cnt[i][1];
      cnt[i+1][1]=-cnt[i][0];
    }
    else if(op==2){
      fugo[i+1][0]=-fugo[i][1];
      fugo[i+1][1]=fugo[i][0];
      hanten[i+1]=hanten[i]+1;
      cnt[i+1][0]=-cnt[i][1];
      cnt[i+1][1]=cnt[i][0];
    }
    else{
      int p;
      cin>>p;
      if(op==3){
        fugo[i+1][0]=-fugo[i][0];
        fugo[i+1][1]=fugo[i][1];
        hanten[i+1]=hanten[i];
        cnt[i+1][0]=-cnt[i][0]+p*2;
        cnt[i+1][1]=cnt[i][1];
      }
      else{
        fugo[i+1][0]=fugo[i][0];
        fugo[i+1][1]=-fugo[i][1];
        hanten[i+1]=hanten[i];
        cnt[i+1][0]=cnt[i][0];
        cnt[i+1][1]=-cnt[i][1]+p*2;
      }
    }
  }
  cin>>q;
  REP(i, q){
    cin>>a[i]>>b[i];
    --b[i];
    if(hanten[a[i]]%2==0){
      cout<<fugo[a[i]][0]*x[b[i]]+cnt[a[i]][0];
      cout<<' ';
      cout<<fugo[a[i]][1]*y[b[i]]+cnt[a[i]][1];
      cout<<'\n';
    }
    else{
      cout<<fugo[a[i]][0]*y[b[i]]+cnt[a[i]][0];
      cout<<' ';
      cout<<fugo[a[i]][1]*x[b[i]]+cnt[a[i]][1];
      cout<<'\n';
    }
  }
  return 0;
}
