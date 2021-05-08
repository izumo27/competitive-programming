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

int dp[252][252];
int cnt[252];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[252];
  cin>>n;
  REP(i, n){
    cin>>a[i];
    a[i]%=200;
    ++cnt[a[i]];
  }
  if(cnt[0]>0){
    cout<<"Yes"<<'\n';
    REP(i, n){
      if(a[i]==0){
        if(i==0){
          cout<<1<<' '<<2<<'\n';
          cout<<2<<' '<<1<<' '<<2<<'\n';
          return 0;
        }
        cout<<1<<' '<<1<<'\n';
        cout<<2<<' '<<1<<' '<<i+1<<'\n';
        return 0;
      }
    }
  }
  REP(i, 200){
    if(cnt[i]>1){
      cout<<"Yes"<<'\n';
      int tmp=0;
      REP(j, n){
        if(a[j]==i){
          cout<<1<<' '<<j+1<<'\n';
          ++tmp;
        }
        if(tmp==2){
          return 0;
        }
      }
    }
  }
  REP(i, n+1){
    REP(j, 200){
      dp[i][j]=-1;
    }
  }
  dp[0][0]=0;
  REP(i, n){
    REP(j, 200){
      if(dp[i][j]>=0){
        if(dp[i][(j+a[i])%200]>0){
          vi b, c;
          int sum=(j+a[i])%200;
          int idx=dp[i][sum];
          while(true){
            if(idx==0){
              break;
            }
            b.push_back(idx);
            sum=(sum-a[idx-1]+200)%200;
            idx=dp[idx][sum];
          }
          c.push_back(i+1);
          sum=j;
          idx=dp[i][sum];
          while(true){
            if(idx==0){
              break;
            }
            c.push_back(idx);
            sum=(sum-a[idx-1]+200)%200;
            idx=dp[idx][sum];
          }
          cout<<"Yes"<<'\n';
          cout<<b.size()<<' ';
          FORR(k, 0, b.size()){
            cout<<b[k]<<" \n"[k==0];
          }
          cout<<c.size()<<' ';
          FORR(k, 0, c.size()){
            cout<<c[k]<<" \n"[k==0];
          }
          return 0;
        }
        if(dp[i+1][j]==-1){
          dp[i+1][j]=dp[i][j];
        }
        dp[i+1][(j+a[i])%200]=i+1;
      }
    }
  }
  cout<<"No"<<'\n';
  return 0;
}
