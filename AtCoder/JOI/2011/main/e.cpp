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

const int MAX_N=114514;

template<typename T> struct BinaryIndexedTree{
	// [1,n]
	int n;
	vector<T> bit;

	BinaryIndexedTree(int n_=1, T d=0){
		init(n_, d);
	}

	void init(int n_=1, T d=0){
		n=n_;
		bit.resize(n+1);
		REP(i, n+1){
			bit[i]=d;
		}
	}

	// a_1からa_iまでの和
	T sum(int i){
		T s=bit[0];
		while(i>0){
			s+=bit[i];
			i-=i&-i;
		}
		return s;
	}

	// a_iにxを加える
	void add(int i, T x){
		while(i<=n){
			bit[i]+=x;
			i+=i&-i;
		}
	}
};

ll cnt[114514];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	pll ba[364364];
	cin>>n;
	REP(i, n){
		cin>>ba[i].second>>ba[i].first;
	}
	sort(ba, ba+n);
	BinaryIndexedTree<ll> bit1(MAX_N, 0), bit2(MAX_N, 0);
	ll ans=0;
	FORR(i, 0, n){
		ll b=ba[i].first, a=ba[i].second;
		bit1.add(a, a);
		bit2.add(a, 1);
		++cnt[a];
		ll lb=0, ub=114514;
		while(ub-lb>1){
			ll mid=(lb+ub)/2;
			if(b*bit2.sum(mid)>=bit1.sum(mid)){
				lb=mid;
			}
			else{
				ub=mid;
			}
		}
		ll tmp1=bit1.sum(lb), tmp2=bit2.sum(lb);
		REP(i, cnt[lb+1]){
			tmp1+=lb+1;
			if(b*(tmp2+1)<tmp1){
				break;
			}
			++tmp2;
		}
		CHMAX(ans, tmp2);
	}
	cout<<ans<<'\n';
	return 0;
}
