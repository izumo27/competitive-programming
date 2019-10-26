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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int Q, q, a, b;
  cin>>Q;
  priority_queue<ll> pq1;
  priority_queue<ll, vl, greater<ll>> pq2;
  cin>>q>>a>>b;
  pq1.push(a);
  ll sum=b-a;
  REP(i, Q-1){
    cin>>q;
    if(q==1){
      cin>>a>>b;
      sum+=b;
      if(pq1.size()==pq2.size()){
        if(a<=pq2.top()){
          pq1.push(a);
          sum-=a;
        }
        else{
          ll tmp=pq2.top();
          pq2.pop();
          pq1.push(tmp);
          pq2.push(a);
          sum=sum-tmp*2+a;
        }
      }
      else{
        if(a>=pq1.top()){
          pq2.push(a);
          sum+=a;
        }
        else{
          ll tmp=pq1.top();
          pq1.pop();
          pq2.push(tmp);
          pq1.push(a);
          sum=sum+tmp*2-a;
        }
      }
    }
    else{
      ll tmp=pq1.top();
      cout<<tmp<<' ';
      cout<<(ll)pq1.size()*tmp-(ll)pq2.size()*tmp+sum<<'\n';
    }
  }
  return 0;
}
