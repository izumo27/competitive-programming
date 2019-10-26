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

#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

#define CHMIN(a, b) a=min((a), (b))
#define CHMAX(a, b) a=max((a), (b))

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

char t[114];

bool issame(int len, char c){
  bool res=true;
  REP(i, len){
    if(t[i]!=c){
      res=false;
      break;
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin>>s;
  int ans=100;
  REP(i, 26){
    REP(j, s.size()){
      t[j]=s[j];
    }
    char c='a'+i;
    int len=s.size();
    while(!issame(len, c)){
      char u[114];
      REP(j, len){
        u[j]=t[j];
      }
      REP(j, len-1){
        if(u[j]==c){
          t[j]=u[j];
        }
        else if(u[j+1]==c){
          t[j]=u[j+1];
        }
        else{
          t[j]=u[j];
        }
      }
      --len;
    }
    ans=min(ans, (int)s.size()-len);
  }
  cout<<ans<<'\n';
  return 0;
}
