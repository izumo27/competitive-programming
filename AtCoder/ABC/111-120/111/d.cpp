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

string w[114514];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll x[1333], y[1333];
  cin>>n;
  bool odd=false, even=false;
  ll ma=-1;
  REP(i, n){
    cin>>x[i]>>y[i];
    if(abs(x[i])+abs(y[i])&1){
      odd=true;
    }
    else{
      even=true;
    }
  }
  if(odd && even){
    cout<<-1<<'\n';
    return 0;
  }
  int m=31, d[40];
  if(even){
    cout<<32<<'\n';
    cout<<1<<' ';
    REP(i, n){
      w[i]="R";
      --x[i];
    }
  }
  else{
    cout<<31<<'\n';
  }
  REP(i, m){
    d[i]=1<<i;
  }
  REP(i, n){
    FORR(j, 0, m){
      if(x[i]+y[i]<0 && x[i]-y[i]<0){
        w[i]+="L";
        x[i]+=d[j];
      }
      else if(x[i]+y[i]>0 && x[i]-y[i]>0){
        w[i]+="R";
        x[i]-=d[j];
      }
      else if(x[i]+y[i]<0 && x[i]-y[i]>0){
        w[i]+="D";
        y[i]+=d[j];
      }
      else{
        w[i]+="U";
        y[i]-=d[j];
      }
    }
  }
  FORR(i, 0, m){
    cout<<d[i]<<" \n"[i==m-1];
  }
  REP(i, n){
    cout<<w[i]<<'\n';
  }
  return 0;
}
