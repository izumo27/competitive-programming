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
	int n, l, t, w[114514], x[114514];
	pii a[214514];
	cin>>n>>l>>t;
	REP(i, n){
		cin>>x[i]>>w[i];
	}
	int cnt=0, m1=2*t/l, m2=2*t%l;
	if(w[0]==1){
		FOR(i, 1, n){
			if(w[i]==2){
				if(x[i]-x[0]<m2){
					cnt=(cnt+m1+1)%n;
				}
				else{
					cnt=(cnt+m1)%n;
				}
			}
		}
	}
	else{
		FOR(i, 1, n){
			if(w[i]==1){
				if(l-(x[i]-x[0])<m2){
					cnt=(cnt+m1+1)%n;
				}
				else{
					cnt=(cnt+m1)%n;
				}
			}
		}
	}
	int m=t%l;
	REP(i, n){
		if(w[i]==1){
			a[i]=pii((x[i]+m)%l, i);
		}
		else{
			a[i]=pii((x[i]-m+l)%l, i);
		}
	}
	sort(a, a+n);
	int s;
	REP(i, n){
		if(a[i].second==0){
			if(w[0]==2 && i+1<n && a[i].first==a[i+1].first){
				s=i+1;
			}
			else{
				s=i;
			}
			break;
		}
	}
	if(w[0]==1){
		s=(s-cnt+n)%n;
	}
	else{
		s=(s+cnt)%n;
	}
	REP(i, n){
		a[i+n]=a[i];
	}
	FOR(i, s, s+n){
		cout<<a[i].first<<'\n';
	}
	return 0;
}
