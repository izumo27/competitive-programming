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

vi g[214514];
int c[214514][2];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, a, b;
  string s;
  cin>>n>>m;
  cin>>s;
  REP(i, m){
    cin>>a>>b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
    ++c[a][s[b]-'A'];
    ++c[b][s[a]-'A'];
  }
  queue<int> q;
  bool v[214514];
  REP(i, n){
    v[i]=true;
  }
  REP(i, n){
    if(!c[i][0] || !c[i][1]){
      q.push(i);
      v[i]=false;
    }
  }
  int cnt=0;
  while(!q.empty()){
    ++cnt;
    int i=q.front();
    q.pop();
    REP(j, g[i].size()){
      --c[g[i][j]][s[i]-'A'];
      if(!c[g[i][j]][s[i]-'A'] && v[g[i][j]]){
        q.push(g[i][j]);
        v[g[i][j]]=false;
      }
    }
  }
  cout<<(cnt!=n ? "Yes" : "No")<<'\n';
  return 0;
}
