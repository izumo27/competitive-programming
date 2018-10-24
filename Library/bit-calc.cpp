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

// sに要素iを加える
int add_element(int s, int i){
	return s|1<<i;
}

// sから要素iを除く
int delete_element(int s, int i){
	return s&~(1<<i);
}

// ある集合supの部分集合を列挙
void subset(int sup){
	int sub=sup;
	do{
		// ここに処理を書く

		sub=(sub-1)&sup;
	}while(sub!=sup);
}

// {0,…, n-1}のサイズkの部分集合を列挙
void subset_k(int n, int k){
	int sub=(1<<k)-1;
	while(sub<1<<n){
		// ここに処理を書く

		int x=sub&-sub, y=sub+x;
		sub=((sub&~y)/x>>1)|y;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
