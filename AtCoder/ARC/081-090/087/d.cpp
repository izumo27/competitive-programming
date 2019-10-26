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

int dx[8334], dy[8334], cntx, cnty;
int dpx[8334][16334], dpy[8334][16334];

void dfs1(int ind, int d){
  if(ind>=cntx || (dpx[ind+1][d+dx[ind]] && dpx[ind+1][d-dx[ind]])){
    return;
  }
  dpx[ind+1][d+dx[ind]]=1;
  dpx[ind+1][d-dx[ind]]=1;
  dfs1(ind+1, d+dx[ind]);
  dfs1(ind+1, d-dx[ind]);
  return;
}

void dfs2(int ind, int d){
  if(ind>=cnty || (dpy[ind+1][d+dy[ind]] && dpy[ind+1][d-dy[ind]])){
    return;
  }
  dpy[ind+1][d+dy[ind]]=1;
  dpy[ind+1][d-dy[ind]]=1;
  dfs2(ind+1, d+dy[ind]);
  dfs2(ind+1, d-dy[ind]);
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  string s;
  cin>>s>>x>>y;
  bool f=true;
  int indx=0, indy=0, len=s.size(), i=0;
  s+='A';
  while(i<len){
    if(s[i]=='T'){
      f=!f;
      ++i;
    }
    else if(f){
      int cnt=0;
      while(i<len){
        ++cnt;
        ++i;
        if(s[i]!='F'){
          break;
        }
      }
      dx[indx]=cnt;
      ++indx;
    }
    else{
      int cnt=0;
      while(i<len){
        ++cnt;
        ++i;
        if(s[i]!='F'){
          break;
        }
      }
      dy[indy]=cnt;
      ++indy;
    }
  }
  cntx=indx;
  cnty=indy;
  dpx[0][8000]=1;
  if(s[0]=='F'){
    dpx[1][dx[0]+8000]=1;
    dfs1(1, dx[0]+8000);
  }
  else{
    dfs1(0, 8000);
  }
  dpy[0][8000]=1;
  dfs2(0, 8000);
  cout<<(dpx[cntx][x+8000] & dpy[cnty][y+8000] ? "Yes" : "No")<<'\n';
  return 0;
}
