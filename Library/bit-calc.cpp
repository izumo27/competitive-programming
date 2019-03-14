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

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

const ll MOD=1000000007ll;
// const ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

// sに要素iを加える
inline int add_element(int s, int i){
	return s|1<<i;
}

// sから要素iを除く
inline int delete_element(int s, int i){
	return s&~(1<<i);
}

// 集合supの部分集合を列挙
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

// msb(x<<1): xより大きい最小の2冪を求める
inline ll msb(ll n) {
 	n=n&0xffffffff00000000LL ? n&0xffffffff00000000LL : n;
 	n=n&0xffff0000ffff0000LL ? n&0xffff0000ffff0000LL : n;
 	n=n&0xff00ff00ff00ff00LL ? n&0xff00ff00ff00ff00LL : n;
 	n=n&0xf0f0f0f0f0f0f0f0LL ? n&0xf0f0f0f0f0f0f0f0LL : n;
 	n=n&0xccccccccccccccccLL ? n&0xccccccccccccccccLL : n;
 	n=n&0xaaaaaaaaaaaaaaaaLL ? n&0xaaaaaaaaaaaaaaaaLL : n;
 	return n;
}

// 立っているビット数を求める (int)
inline int bit_count(int n){
	n=((n>>1)&0x55555555)+(n&0x55555555);
	n=((n>>2)&0x33333333)+(n&0x33333333);
	n=((n>>4)&0x0f0f0f0f)+(n&0x0f0f0f0f);
	n=((n>>8)&0x00ff00ff)+(n&0x00ff00ff);
	n=((n>>16)&0x0000ffff)+(n&0x0000ffff);
	return n;
}

// 立っているビット数を求める (ll)
inline ll bit_count(ll n) {
	n=((n>>1)&0x5555555555555555LL)+(n&0x5555555555555555LL);
	n=((n>>2)&0x3333333333333333LL)+(n&0x3333333333333333LL);
	n=((n>>4)&0x0f0f0f0f0f0f0f0fLL)+(n&0x0f0f0f0f0f0f0f0fLL);
	n=((n>>8)&0x00ff00ff00ff00ffLL)+(n&0x00ff00ff00ff00ffLL);
	n=((n>>16)&0x00ff00ff00ff00ffLL)+(n&0x0000ffff0000ffffLL);
	n=((n>>32)&0x00000000ffffffffLL)+(n&0x00000000ffffffffLL);
	return n;
}

// [0, n]のxor
inline ll xorxor(ll n) {
	ll res=((n+1)>>1)&1;
	REP(i, 60){
		if(n>>i&1){
			res|=(1^(n&1))<<i;
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
