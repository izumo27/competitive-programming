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

int a[40][40], ans[40][40];
int n, b[3], l[40][40], r[40][40];
constexpr int INF=1e8;

int score(){
  int res=0;
  REP(x,3){
    REP(i, n)REP(j, n){
      int t=0;
      FOR(k, i, n){
        t+=a[k][j];
        if(t>=b[x]) break;
      }
      if(t==b[x]) ++res;
    }
  }
  REP(x,3){
    REP(i, n)REP(j, n){
      int t=0;
      FOR(k, j, n){
        t+=a[i][k];
        if(t>=b[x]) break;
      }
      if(t==b[x]) ++res;
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  clock_t start=clock();
  cin>>n;
  REP(i, 3) cin>>b[i];
  REP(i, n)REP(j, n) cin>>l[i][j];
  REP(i, n)REP(j, n) cin>>r[i][j];
  int s=0;
  REP(x, 3){
    REP(d, 2){
      int zero=(d==0 ? 0 : n-1);
      int dx=(d==0 ? 1 : -1);
      REP(j, n){
        a[zero][j]=r[zero][j];
      }
      REP(j, n){
        int sum=a[zero][j], k=zero;
        for(int i=zero+dx; ; i+=dx){
          if(i==-1 || i==n) break;
          while(sum+l[i][j]>b[x]){
            sum-=a[k][j];
            k+=dx;
          }
          if(b[x]<=sum+r[i][j]){
            a[i][j]=b[x]-sum;
            sum+=a[i][j];
          }
          else{
            a[i][j]=r[i][j];
            sum+=a[i][j];
          }
        }
      }
      int res=score();
      if(s<res){
        swap(a, ans);
        s=res;
      }
    }
    REP(d, 2){
      int zero=(d==0 ? 0 : n-1);
      int dy=(d==0 ? 1 : -1);
      REP(i, n){
        a[i][zero]=r[i][zero];
      }
      REP(i, n){
        int sum=a[i][zero], k=zero;
        for(int j=zero+dy; ; j+=dy){
          if(j==-1 || j==n) break;
          while(sum+l[i][j]>b[x]){
            sum-=a[i][k];
            k+=dy;
          }
          if(b[x]<=sum+r[i][j]){
            a[i][j]=b[x]-sum;
            sum+=a[i][j];
          }
          else{
            a[i][j]=r[i][j];
            sum+=a[i][j];
          }
        }
      }
      int res=score();
      if(s<res){
        swap(a, ans);
        s=res;
      }
    }
  }
  REP(i, n)REP(j, n) a[i][j]=ans[i][j];
  REP(x, INF){
    REP(i, n)REP(j, n){
      FOR(m, l[i][j], r[i][j]+1){
        clock_t end=clock();
        // ミリ秒
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        if(time>2990){
          x=INF;i=n;j=n;
          break;
        }
        a[i][j]=m;
        int res=score();
        if(s<res){
          ans[i][j]=a[i][j];
          s=res;
        }
        else{
          a[i][j]=ans[i][j];
        }
      }
    }
  }
  REP(i, n)REP(j, n){
    cout<<a[i][j]<<" \n"[j==n-1];
  }
  return 0;
}
