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

int ans[252521];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  cin>>n;
  vi g[252521];
  REP(i, n-1){
    int a, b;
    cin>>a>>b;
    --a;--b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  queue<pii> que;
  que.emplace(0, 1);
  ans[0]=1;
  int one=1, two=0;
  while(que.size()){
    auto xy=que.front();que.pop();
    int x=xy.first, y=xy.second;
    for(auto v : g[x]){
      if(ans[v]){
        continue;
      }
      int yy=(y==0 ? 1 : 0);
      if(yy){
        ans[v]=1;
        ++one;
      }
      else{
        ans[v]=2;
        ++two;
      }
      que.emplace(v, yy);
    }
  }
  bool three=false;
  if(one<=n/3){
    REP(i, n){
      if(ans[i]==1){
        ans[i]=0;
        three=true;
      }
    }
  }
  else if(two<=n/3){
    REP(i, n){
      if(ans[i]==2){
        ans[i]=0;
        three=true;
      }
    }
  }
  if(three){
    int zero=3;
    one=1;two=2;
    REP(i, n){
      if(ans[i]){
        if(one<=n){
          ans[i]=one;
          one+=3;
        }
        else if(two<=n){
          ans[i]=two;
          two+=3;
        }
        else{
          ans[i]=0;
        }
      }
      if(ans[i]==0){
        ans[i]=zero;
        zero+=3;
      }
    }
  }
  else{
    int zero=3;
    one=1;two=2;
    REP(i, n){
      if(ans[i]==1){
        if(one<=n){
          ans[i]=one;
          one+=3;
        }
        else{
          ans[i]=0;
        }
      }
      else{
        if(two<=n){
          ans[i]=two;
          two+=3;
        }
        else{
          ans[i]=0;
        }
      }
      if(ans[i]==0){
        if(zero<=n){
          ans[i]=zero;
          zero+=3;
        }
        else if(one<=n){
          ans[i]=one;
          one+=3;
        }
        else{
          ans[i]=two;
          two+=3;
        }
      }
    }
  }
  REP(i, n){
    cout<<ans[i]<<" \n"[i==n-1];
  }
  return 0;
}
