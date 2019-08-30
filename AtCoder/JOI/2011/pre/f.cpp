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

constexpr int mod=1e5;

// なし，j,jo
int crt[1<<20][3], nxt[1<<20][3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout<<setprecision(10)<<fixed;
	int m, n;
	char s[25][25];
	cin>>m>>n;
	int ans=1;
	REP(i, m){
		REP(j, n){
			cin>>s[i][j];
			if(s[i][j]=='?'){
				ans=ans*3%mod;
			}
		}
	}
	crt[0][0]=1;
	REP(i, m){
		REP(j, 1<<n){
			crt[j][0]+=crt[j][1];
			crt[j][1]=0;
		}
		REP(j, n){
			REP(k, 1<<n){
				REP(l, 3){
					nxt[k][l]=0;
				}
			}
			REP(k, 1<<n){
				int tmp=k&~(1<<j);
				if(s[i][j]=='?' || s[i][j]=='J'){
					(nxt[tmp][1]+=crt[k][0]+crt[k][1]+crt[k][2])%=mod;
				}
				if(s[i][j]=='?' || s[i][j]=='O'){
					if(j){
						(nxt[tmp|(1<<(j-1))][2]+=crt[k][1])%=mod;
					}
					(nxt[tmp][0]+=crt[k][0]+crt[k][2])%=mod;
				}
				if(s[i][j]=='?' || s[i][j]=='I'){
					if(!(k>>j&1)){
						(nxt[tmp][0]+=crt[k][0]+crt[k][1]+crt[k][2])%=mod;
					}
				}
			}
			swap(crt, nxt);
		}
	}
	REP(i, 1<<n){
		REP(j, 3){
			ans-=crt[i][j];
			(ans+=mod)%=mod;
			// DEBUG(ans);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
