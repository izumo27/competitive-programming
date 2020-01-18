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

const int INF=1e9;

template<typename T> struct BinaryIndexedTree{
  // [1,n]
  int n;
  vector<T> bit;

  BinaryIndexedTree(int n_=1, T d=0){
    init(n_, d);
  }

  void init(int n_=1, T d=0){
    n=n_;
    bit.resize(n+1);
    REP(i, n+1){
      bit[i]=d;
    }
  }

  // a_1からa_iまでの和
  T sum(int i){
    T s=bit[0];
    while(i>0){
      s+=bit[i];
      i-=i&-i;
    }
    return s;
  }

  // a_iにxを加える
  void add(int i, T x){
    while(i<=n){
      bit[i]+=x;
      i+=i&-i;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[20], b[50];
  cin>>n;
  REP(i, n){
    cin>>a[i];
  }
  REP(i, n){
    cin>>b[i];
  }
  int ans=INF;
  REP(i, 1<<n){
    vi u, v, w;
    REP(j, n){
      if(i>>j&1){
        u.push_back(a[j]);
        v.push_back(j);
        if(j&1){
          w.push_back(1);
        }
        else{
          w.push_back(0);
        }
      }
      else{
        u.push_back(b[j]);
        v.push_back(j);
        if(j&1){
          w.push_back(0);
        }
        else{
          w.push_back(1);
        }
      }
    }
    vi ord(n);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&u, &v](int x, int y){
      if(u[x]==u[y]) return v[x]<v[y];
      return u[x]<u[y];
    });
    int idx=0;
    bool ok=true;
    vi x;
    while(idx<n){
      int tmp=idx, cnt=0;
      vi odd, evn;
      if(w[ord[idx]]){
        ++cnt;
        odd.push_back(idx);
      }
      else{
        evn.push_back(idx);
      }
      while(idx<n-1 && u[ord[idx]]==u[ord[idx+1]]){
        if(w[ord[idx+1]]){
          ++cnt;
          odd.push_back(idx+1);
        }
        else{
          evn.push_back(idx+1);
        }
        ++idx;
      }
      int m=idx-tmp+1;
      if(tmp&1){
        if(m/2!=m-cnt){
          ok=false;
          break;
        }
      }
      else{
        if(m/2!=cnt){
          ok=false;
          break;
        }
      }
      int oi=0, ei=0;
      FOR(j, tmp, idx+1){
        if(j&1){
          x.push_back(ord[odd[oi]]);
          ++oi;
        }
        else{
          x.push_back(ord[evn[ei]]);
          ++ei;
        }
      }
      ++idx;
    }
    if(ok){
      BinaryIndexedTree<int> bt(n);
      int sum=0;
      REP(j, n){
        sum+=j-bt.sum(x[j]+1);
        bt.add(x[j]+1, 1);
      }
      CHMIN(ans, sum);
    }
  }
  cout<<(ans==INF ? -1 : ans)<<'\n';
  return 0;
}
