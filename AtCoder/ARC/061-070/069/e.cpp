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

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

ll ans[125252];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
  int n;
  vl a(125252);
  cin>>n;
  auto cmp=[](pii a, pii b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
  };
  priority_queue<pii, vector<pii>, decltype(cmp)> q{cmp};
  REP(i, n){
    cin>>a[i];
    q.push(pii(a[i], i));
  }
  int cnt=0, mi=1e9;
  while(q.size()){
    pii tmp=q.top();
    int fir=tmp.first;
    int idx=-1;
    while(q.size() && q.top().first==fir){
      // DEBUG(q.top().second);
      idx=q.top().second;
      q.pop();
      ++cnt;
    }
    ll dif=fir-(q.size() ? q.top().first : 0);
    CHMIN(mi, idx);
    ans[mi]+=dif*cnt;
  }
  REP(i, n){
    cout<<ans[i]<<'\n';
  }
	return 0;
}
