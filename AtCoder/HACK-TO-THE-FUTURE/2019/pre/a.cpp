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

int n, m, l;
string s[514];
char board[29][29];
// シミュレーション用
char board_sub[29][29];
// 反時計回り
int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1}, score;
// 焼きなましの許容ライン、徐々に厳しくする
double force_line;

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

// 得点計算
int eval(){
	int used[29][29];
	REP(i, m){
		REP(j, m){
			used[i][j]=0;
		}
	}
	REP(i, n){
		int x=14, y=14, d=0;
		REP(j, l){
			if(s[i][j]=='S'){
				if(board_sub[x][y]=='D' || board_sub[x][y]=='T'){
					int r;
					if(board_sub[x][y]=='D') r=2;
					else r=3;
					REP(k, r){
						if(board_sub[x+dx[d]][y+dy[d]]=='#'){
							break;
						}
						x+=dx[d];
						y+=dy[d];
					}
				}
				else if(board_sub[x+dx[d]][y+dy[d]]!='#'){
					x+=dx[d];
					y+=dy[d];
				}
			}
			else if(s[i][j]=='L'){
				if(board_sub[x][y]=='D'){
					d+=2;
					if(d>=4) d-=4;
				}
				else if(board_sub[x][y]=='T'){
					d+=3;
					if(d>=4) d-=4;
				}
				else if(board_sub[x][y]=='R'){
					--d;
					if(d<0) d+=4;
				}
				else{
					++d;
					if(d>=4) d-=4;
				}
			}
			else{
				if(board_sub[x][y]=='D'){
					d-=2;
					if(d<0) d+=4;
				}
				else if(board_sub[x][y]=='T'){
					d-=3;
					if(d<0) d+=4;
				}
				else if(board_sub[x][y]=='L'){
					++d;
					if(d>=4) d-=4;
				}
				else{
					--d;
					if(d<0) d+=4;
				}
			}
		}
		++used[x][y];
	}
	int res=0;
	REP(i, m){
		REP(j, m){
			if(used[i][j]==1){
				res+=10;
			}
			else if(used[i][j]==2){
				res+=3;
			}
			else if(used[i][j]==3){
				++res;
			}
		}
	}
	return res;
}

// ランダムにマスを選んで山登り
// 徐々に選ぶマスを減らす
void simulate(double size){
	int num_size=(int)size;
	pair<unsigned int, unsigned int> num[50];
	REP(i, num_size){
		num[i].first=xor32()%27+1;
		num[i].second=xor32()%27+1;
	}
	REP(i, num_size){
		unsigned int random=xor32();
		if(random%16==0){
			random=xor32();
			if(random%32==0){
				random=xor32();
				if(random&1){
					board_sub[num[i].first][num[i].second]='D';
				}
				else{
					board_sub[num[i].first][num[i].second]='T';
				}
			}
			else{
				random=xor32();
				if(random&1){
					board_sub[num[i].first][num[i].second]='L';
				}
				else{
					board_sub[num[i].first][num[i].second]='R';
				}
			}
		}
		else{
			board_sub[num[i].first][num[i].second]='.';
		}
	}

	int score_sub=eval();
	// 更新
	if(score<score_sub){
		score=score_sub;
		REP(i, num_size){
			board[num[i].first][num[i].second]=board_sub[num[i].first][num[i].second];
		}
	}
	// 更新しなければsubを戻す
	else{
		REP(i, num_size){
			board_sub[num[i].first][num[i].second]=board[num[i].first][num[i].second];
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>l;
	REP(i, n){
		cin>>s[i];
	}
	// 初期化、外側のマスはこれ以降変更しない
	REP(i, m){
		REP(j, m){
			if(i==0 || i==m-1 || j==0 || j==m-1){
				board[i][j]='#';
				board_sub[i][j]='#';
			}
			else{
				board[i][j]='.';
				board_sub[i][j]='.';
			}
		}
	}

	score=eval();
	ull time_limit=2965;
	ull st=current_time_mills();
	ull et=st+time_limit;
	ull current_time=st;
	// 確率定数
	double C=time_limit;
	double size;
	while(current_time<et){
		current_time=current_time_mills();
		// force_line=(et-current_time)/C;
		size=(et-current_time)/C*20+10;
		REP(i, 10){
			simulate(size);
		}
	}

	// 出力
	REP(i, m){
		REP(j, m){
			cout<<board[i][j];
		}
		cout<<'\n';
	}
	return 0;
}
