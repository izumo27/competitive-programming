#include <bits/stdc++.h>
#include <sys/time.h>

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

// 時刻取得（ミリ秒）
ull current_time_mills(){
	struct timeval _time;
	gettimeofday(&_time, NULL);
	return _time.tv_sec*1000+_time.tv_usec/1000;
}

// 乱数
unsigned int xor32(){
	static unsigned int x=2463534242;
	x=x^(x<<13);x=x^(x>>17);
	return x=x^(x<<15);
}

int n;
pii xy[252];
double d[252][252];
int ans[252], ans_sub[252];
bool used[252];

// 分散のn倍
double var(){
	double ave=0;
	REP(i, n){
		ave+=d[ans_sub[i]][ans_sub[i+1]];
	}
	ave/=n;
	double res=0;
	REP(i, n){
		res+=(d[ans_sub[i]][ans_sub[i+1]]-ave)*(d[ans_sub[i]][ans_sub[i+1]]-ave);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	REP(i, n){
		cin>>xy[i].first>>xy[i].second;
	}
	REP(i, n-1){
		FOR(j, i+1, n){
			d[i][j]=d[j][i]=sqrt((xy[i].first-xy[j].first)*(xy[i].first-xy[j].first)+(xy[i].second-xy[j].second)*(xy[i].second-xy[j].second));
		}
	}
	double variance=1e9;
	// 探索
	for(double dis=0; dis<400; dis+=10){
		REP(i, n){
			REP(j, n){
				used[j]=false;
			}
			ans_sub[0]=ans_sub[n]=i;
			used[i]=true;
			REP(j, n-1){
				int cand=-1;
				double cand_dis=5000;
				REP(k, n){
					if(used[k]){
						continue;
					}
					if(abs(cand_dis-dis)>abs(d[ans_sub[j]][k]-dis)){
						cand_dis=d[ans_sub[j]][k];
						cand=k;
					}
				}
				ans_sub[j+1]=cand;
				used[cand]=true;
			}
			double tmp=var();
			if(variance>tmp){
				variance=tmp;
				REP(j, n+1){
					ans[j]=ans_sub[j];
				}
			}
		}
	}

	// 出力
	REP(i, n){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
