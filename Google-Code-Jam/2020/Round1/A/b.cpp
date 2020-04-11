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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int T;
  cin>>T;
  REP(case_num, T){
    cout<<"Case #"<<case_num+1<<": "<<'\n';
    int n;
    cin>>n;
    bool used[40][40];
    REP(i, 40){
      REP(j, 40){
        used[i][j]=false;
      }
    }
    int m=n;
    vi v;
    int cnt=0;
    while(m>0){
      if(m&1){
        v.push_back(cnt);
      }
      m/=2;
      ++cnt;
    }
    int sz=v.size();
    bool right=true;
    FORR(i, 0, sz-1){
      int s=v[i], t=v[i+1];
      if(right){
        REP(j, t+1-(t-s-1)){
          used[t][j]=true;
        }
        FOR(j, s+1, t){
          REP(k, j-s){
            used[j][j-k]=true;
          }
        }
      }
      else{
        FOR(j, (t-s-1), t+1){
          used[t][j]=true;
        }
        FOR(j, s+1, t){
          REP(k, j-s){
            used[j][k]=true;
          }
        }
      }
      right=!right;
    }
    REP(i, v[0]){
      REP(j, i+1){
        used[i][j]=true;
      }
    }
    if(right){
      used[v[0]][0]=true;
    }
    else{
      used[v[0]][v[0]]=true;
    }
    // REP(i, 6){
    //   REP(j, i+1){
    //     cout<<used[i][j]<<" \n"[j==i];
    //   }
    // }
    vector<pii> ans;
    int curx=v[sz-1], cury=0;
    while(1){
      // DEBUG(curx);DEBUG(cury);
      if(curx==0 && cury==0){
        ans.push_back(pii(0, 0));
        break;
      }
      while(cury>=0 && used[curx][cury]){
        ans.push_back(pii(curx, cury));
        used[curx][cury]=false;
        if(used[curx][cury+1]){
          ++cury;
        }
        else if(cury>0 && used[curx][cury-1]){
          --cury;
        }
      }
      if(cury<0){
        cury=0;
      }
      if(cury>curx){
        cury=curx;
      }
      --curx;
      // DEBUG(curx);DEBUG(cury);
      if(cury>0 && used[curx][cury-1]){
        --cury;
      }
    }
    FORR(i, 0, ans.size()){
      cout<<ans[i].first+1<<' '<<ans[i].second+1<<'\n';
    }
  }
  return 0;
}
