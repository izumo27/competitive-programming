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

ll sum[1333];
bool abit[1252525][43], sum_bit[43];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	ll a[1333];
	cin>>n>>k;
	REP(i, n){
		cin>>a[i];
		sum[i+1]=sum[i]+a[i];
	}
	int cnt=0;
	REP(i, n-1){
		FOR(j, i+1, n){
			ll tmp=sum[j+1]-sum[i];
			int ind=42;
			while(tmp>0){
				abit[cnt][ind]=tmp&1;
				tmp/=2;
				--ind;
			}
			++cnt;
		}
	}
	vi x;
	REP(i, cnt){
		x.push_back(i);
	}
	REP(i, 43){
		int cnt2=0;
		vi y;
		for(auto &xx : x){
			if(abit[xx][i]){
				++cnt2;
				y.push_back(xx);
			}
		}
		if(cnt2>=k){
			sum_bit[i]=true;
			x.erase(ALL(x));
			for(auto &yy : y){
				x.push_back(yy);
			}
		}
	}
	ll ans=0;
	REP(i, 43){
		ans*=2;
		if(sum_bit[i]){
			++ans;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
