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

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

int n, q;
string s;
char t[252521], d[252521];

bool is_ok1(int mid){
  REP(i, q){
    if(mid==0 && s[mid]==t[i] && d[i]=='L'){
      return true;
    }
    if(s[mid]==t[i]){
      if(d[i]=='L'){
        --mid;
      }
      else{
        ++mid;
      }
    }
  }
  return false;
}

bool is_ok2(int mid){
  REP(i, q){
    if(mid==n-1 && s[mid]==t[i] && d[i]=='R'){
      return true;
    }
    if(s[mid]==t[i]){
      if(d[i]=='L'){
        --mid;
      }
      else{
        ++mid;
      }
    }
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  cin>>n>>q>>s;
  REP(i, q){
    cin>>t[i]>>d[i];
  }
  int lb1=-1, ub1=n+1;
  while(ub1-lb1>1){
    int mid=(lb1+ub1)/2;
    if(is_ok1(mid)){
      lb1=mid;
    }
    else{
      ub1=mid;
    }
  }
  int lb2=-1, ub2=n;
  while(ub2-lb2>1){
    int mid=(lb2+ub2)/2;
    if(is_ok2(mid)){
      ub2=mid;
    }
    else{
      lb2=mid;
    }
  }
  // DEBUG(lb1);
  // DEBUG(ub1);
  // DEBUG(lb2);
  // DEBUG(ub2);
  cout<<n-min(n, lb1+1+n-ub2)<<'\n';
  return 0;
}
