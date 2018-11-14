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

const int MAX_N=1<<17;

struct SegmentTree{
	int n;
	vi dat;

	SegmentTree(int n_=1){
		init(n_);
	}

	// n要素で初期化
	void init(int n_=1){
		n=1;
		while(n<n_){
			n<<=1;
		}
		dat.resize(n*2-1);
		REP(i, n*2-1){
			dat[i]=INT_MAX;
		}
	}

	// k番目を(0-indexed)をaに変更
	void update(int k, int a){
		k+=n-1;
		dat[k]=a;
		while(k>0){
			k=(k-1)/2;
			dat[k]=min(dat[k*2+1], dat[k*2+2]);
		}
	}

	// [a, b)の最小値を求める
	// k: 節点の番号、その節点は[l, r)に対応づく
	// 外から呼び出すときはquery(a, b, 0, 0, n)
	int query(int a, int b, int k, int l, int r){
		// [a, b)と[l, r)が交差しなければINT_MAX
		if(r<=a || b<=l){
			return INT_MAX;
		}
		// [a, b)と[l, r)が完全に含んでいればこの節点の値
		if(a<=l && r<=b){
			return dat[k];
		}
		// そうでなければ2つの子の最小値
		else{
			int v1=query(a, b, k*2+1, l, (l+r)/2), v2=query(a, b, k*2+2, (l+r)/2, r);
			return min(v1, v2);
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
