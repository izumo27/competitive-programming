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

int num[3], cnt[3];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n, a[125252];
  cin>>n;
  REP(i, 3){
    num[i]=-1;
  }
  REP(i, n){
    cin>>a[i];
    bool ok=false;
    REP(j, 3){
      if(num[j]==-1){
        num[j]=a[i];
        ++cnt[j];
        ok=true;
        break;
      }
      else if(num[j]==a[i]){
        ++cnt[j];
        ok=true;
        break;
      }
    }
    if(!ok){
      cout<<"No"<<'\n';
      return 0;
    }
  }
  if(num[1]==-1){
    cout<<(num[0]==0 ? "Yes" : "No")<<'\n';
    return 0;
  }
  if(num[2]==-1){
		if(n%3!=0){
			cout<<"No"<<'\n';
			return 0;
		}
		if(!(cnt[0]*2==cnt[1]) && !(cnt[0]==cnt[1]*2)){
			cout<<"No"<<'\n';
			return 0;
		}
		int idx=0;
		if(cnt[0]*2==cnt[1]){
			idx=1;
		}
		bool can=false;
		if(0==num[(idx+1)&1]){
			can=true;
		}
		cout<<(can ? "Yes" : "No")<<'\n';
	}
	else{
		if(n%3!=0){
			cout<<"No"<<'\n';
			return 0;
		}
		REP(i, 2){
			if(cnt[i]!=cnt[i+1]){
				cout<<"No"<<'\n';
				return 0;
			}
		}
		bool can=false;
		if((num[0]^num[1])==num[2]){
			can=true;
		}
		cout<<(can ? "Yes" : "No")<<'\n';
	}
	return 0;
}
