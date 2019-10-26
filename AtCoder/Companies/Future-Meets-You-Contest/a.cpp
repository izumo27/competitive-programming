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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, K, A, a[31333];
	priority_queue<pii> que1, que2;
	cin>>n>>K;
	REP(p, n){
		cin>>A;
		a[p]=A-1;
		if(a[p]-p>0){
			que1.push(pii(a[p]-p, p));
		}
		else{
			que2.push(pii(p-a[p], p));
		}
	}

	int i, j, k, l, v, zero=1, one=1;;

	while(K>0 && !que1.empty() && !que2.empty()){
		pii q1=que1.top();
		pii q2=que2.top();
		que1.pop();
		que2.pop();
		v=min(q1.first, q2.first);
		i=q1.second;
		k=q2.second;
		cout<<i+1<<' '<<i+1<<' '<<k+1<<' '<<k+1<<' '<<v<<'\n';
		--K;
		a[i]-=v;
		a[k]+=v;
		if(a[i]-i>0){
			que1.push(pii(a[i]-i, i));
		}
		else{
			que2.push(pii(k-a[k], k));
		}
	}

	REP(p, K){
		cout<<1<<' '<<1<<' '<<2<<' '<<2<<' '<<0<<'\n';
	}
	return 0;
}
