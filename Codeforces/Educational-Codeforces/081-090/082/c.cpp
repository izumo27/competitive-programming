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

string ans="abcdefghijklmnopqrstuvwxyz";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    int alp[26][2];
    REP(i, 26){
      alp[i][0]=alp[i][1]=-1;
    }
    int n=s.size();
    if(n==1){
      cout<<"YES"<<'\n';
      cout<<ans<<'\n';
      continue;
    }
    bool ok=true;
    REP(i, n){
      int o=s[i]-'a';
      if(i>0){
        int l=s[i-1]-'a';
        if(alp[o][0]==-1 || alp[o][0]==l){
          alp[o][0]=l;
        }
        else if(alp[o][1]==-1 || alp[o][1]==l){
          alp[o][1]=l;
        }
        else{
          ok=false;
          break;
        }
      }
      if(i<n-1){
        int r=s[i+1]-'a';
        if(alp[o][0]==-1 || alp[o][0]==r){
          alp[o][0]=r;
        }
        else if(alp[o][1]==-1 || alp[o][1]==r){
          alp[o][1]=r;
        }
        else{
          ok=false;
          break;
        }
      }
    }
    int cnt=0;
    int x=-1, y=-1;
    REP(i, 26){
      if(alp[i][0]!=-1 && alp[i][1]==-1){
        ++cnt;
        if(x!=-1){
          y=i;
        }
        else{
          x=i;
        }
      }
    }
    if(cnt!=2){
      ok=false;
    }
    if(!ok){
      cout<<"NO"<<'\n';
      continue;
    }
    cout<<"YES"<<'\n';
    bool used[26];
    REP(i, 26){
      used[i]=false;
    }
    cout<<ans[x];
    used[x]=true;
    int cur=alp[x][0];
    int pre=x;
    while(cur!=y){
      cout<<ans[cur];
      used[cur]=true;
      if(alp[cur][0]==pre){
        pre=cur;
        cur=alp[cur][1];
      }
      else{
        pre=cur;
        cur=alp[cur][0];
      }
    }
    cout<<ans[y];
    used[y]=true;
    REP(i, 26){
      if(!used[i]){
        cout<<ans[i];
      }
    }
    cout<<'\n';
  }
  return 0;
}
