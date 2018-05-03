#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for(int i=0; i<n; ++i)
#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define FORR(i, a, b) for(int i=b-1; i>=a; --i)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	string s;
	cin>>n>>k>>s;
	string t=s;
	REP(i, n){
		int tmp=i;
		REP(j, n-i-1){
			if(t[tmp]>t[i+1+j]){
				string u=t;
				swap(u[i], u[i+1+j]);
				int cnt=0;
				REP(l, n){
					if(s[l]!=u[l]) ++cnt;
				}
				if(cnt<=k) tmp=i+1+j;
			}
		}
		swap(t[i], t[tmp]);
	}
	cout<<t<<'\n';
	return 0;
}
