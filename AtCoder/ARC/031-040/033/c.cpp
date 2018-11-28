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

const int MAX_N=214514;

// [1,n]
int bit[MAX_N+1], n=MAX_N;

// a_1からa_iまでの和
int bit_sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}

// a_iにxを加える
void bit_add(int i, int x){
	while(i<=n){
		bit[i]+=x;
		i+=i&-i;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q, t, x;
	cin>>q;
	REP(i, q){
		cin>>t>>x;
		if(t==1){
			bit_add(x, 1);
		}
		else{
			int lb=0, ub=214514;
			while(ub-lb>1){
				int mid=(lb+ub)/2;
				if(bit_sum(mid)>=x){
					ub=mid;
				}
				else{
					lb=mid;
				}
			}
			cout<<ub<<'\n';
			bit_add(ub, -1);
		}
	}
	return 0;
}
