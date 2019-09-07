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

template<typename T> struct SegmentTree_max{
	int n;
	vector<T> node;
	T MIN;

	SegmentTree_max(const vector<T> &v, const T &MIN_=0){
		init(v, MIN_);
	}

	// nodeの初期化
	void init(const vector<T> &v, const T &MIN_){
		int n_=v.size();
		n=1;
		while(n<n_){
			n<<=1;
		}
		node.resize(n*2-1);
		MIN=MIN_;
		REP(i, n_){
			node[i+n-1]=v[i];
		}
		FORR(i, 0, n-1){
			node[i]=max(node[i*2+1], node[i*2+2]);
		}
	}

	// k番目(0-indexed)をaに変更
	void update(int k, const T &a){
		k+=n-1;
		node[k]=a;
		while(k>0){
			k=(k-1)/2;
			node[k]=max(node[k*2+1], node[k*2+2]);
		}
	}

	// [a, b)の最大値を求める
	// k: 節点の番号、その節点は[l, r)に対応づく
	T query(int a, int b, int k, int l, int r){
		// [a, b)と[l, r)が交差しなければMIN
		if(r<=a || b<=l){
			return MIN;
		}
		// [a, b)と[l, r)が完全に含んでいればこの節点の値
		if(a<=l && r<=b){
			return node[k];
		}
		// そうでなければ2つの子の最大値
		else{
			T v1=query(a, b, k*2+1, l, (l+r)/2), v2=query(a, b, k*2+2, (l+r)/2, r);
			return max(v1, v2);
		}
	}

	T query(int a, int b){
		return query(a, b, 0, 0, n);
	}
};

ll n;

ll f(SegmentTree_max<ll> &st, ll r, ll p){
	ll lb=-1, ub=r;
	while(ub-lb>1){
		ll mid=(lb+ub)/2;
		if(st.query(mid, r+1)<=p){
			ub=mid;
		}
		else{
			lb=mid;
		}
	}
	return ub;
}

ll g(SegmentTree_max<ll> &st, ll l, ll p){
	ll lb=l, ub=n+2;
	while(ub-lb>1){
		ll mid=(lb+ub)/2;
		if(st.query(l, mid)<=p){
			lb=mid;
		}
		else{
			ub=mid;
		}
	}
	return lb;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	cin>>n;
	vl p(n+2);
	FOR(i, 1, n+1){
		cin>>p[i];
	}
	p[0]=p[n+1]=0;
	SegmentTree_max<ll> st(p);
	ll ans=0;
	FOR(i, 1, n+1){
		ll l1=f(st, i, p[i]);
		ll l2=f(st, l1-2, p[i]);
		ll r1=g(st, i, p[i]);
		ll r2=g(st, r1+1, p[i]);
		if(p[l2]>p[i]) l2=l1-1;
		--r1;--r2;
		// cout<<l2<<' '<<l1<<' '<<r1<<' '<<r2<<'\n';
		if(l1<1){
			if(r1<=n){
				ans+=p[i]*i*(min(r2, n)-r1);
			}
		}
		else if(r1>n){
			if(l1>=1){
				ans+=p[i]*(l1-max(l2, 1ll))*(n-i+1);
			}
		}
		else{
			ans+=p[i]*((i-l1+1)*(min(r2, n)-r1)+(l1-max(l2, 1ll))*(r1-i+1));
		}
		// DEBUG(ans);
	}
	cout<<ans<<'\n';
	return 0;
}
