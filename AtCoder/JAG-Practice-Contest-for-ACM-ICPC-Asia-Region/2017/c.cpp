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

const int MAX_N=1e6;

bool is_prime_small[MAX_N+1];
int cnt[MAX_N+1];
int num[MAX_N+1];

int segment_sieve(int a, int b){
  for(ll i=2; i*i<b; ++i){
    is_prime_small[i]=true;
  }
  REP(i, b-a){
    num[i]=i+a;
  }
  for(int i=2; i*i<b; ++i){
    if(is_prime_small[i]){
      for(ll j=2*i; j*j<b; j+=i){
        is_prime_small[j]=false;
      }
      ll tmp=i;
      while(tmp<b){
        for(ll j=max(2ll, (a+tmp-1)/tmp)*tmp; j<b; j+=tmp){
          ++cnt[j-a];
          num[j-a]/=i;
        }
        tmp*=i;
      }
    }
  }
  int res=0;
  REP(i, b-a){
    if(num[i]!=1){
      ++cnt[i];
    }
    if(is_prime_small[cnt[i]]){
      ++res;
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l, r;
  cin>>l>>r;
  cout<<segment_sieve(l, r+1)<<'\n';
  return 0;
}
