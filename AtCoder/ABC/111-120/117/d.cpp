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

int bit[114514][40], kbit[40], ans[40];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll k, a;
	cin>>n>>k;
	REP(i, n){
		cin>>a;
		int cnt=0;
		while(a>0){
			bit[i][cnt++]=a&1;
			a/=2;
		}
	}
	int kcnt=0;
	while(k>0){
		kbit[kcnt++]=k&1;
		k/=2;
	}
	bool lower=false;
	FORR(i, 0, 40){
		int cnt=0;
		REP(j, n){
			if(bit[j][i]){
				++cnt;
			}
		}
		if(cnt*2<n){
			if(!lower && kbit[i]==0){
				ans[i]=cnt;
			}
			else{
				ans[i]=n-cnt;
			}
		}
		else{
			ans[i]=cnt;
			if(!lower && kbit[i]==1){
				lower=true;
			}
		}
	}
	ll res=0, beki=1;
	REP(i, 40){
		// DEBUG(res);
		// DEBUG(ans[i]);
		res+=beki*ans[i];
		beki*=2;
	}
	cout<<res<<'\n';
	return 0;
}
