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

int gcd(int a,int b){
	return b==0 ? a : gcd(b, a%b);
}

int lcm(int a, int b){
	return a/gcd(a, b)*b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin>>s>>t;
	int a=s.size(), b=t.size();
	REP(i, a){
		if(a-i<b) break;
		REP(j, b){
			if(s[a-1-i-j]!=t[b-1-j] && s[a-1-i-j]!='?') break;
			if(j==b-1){
				REP(k, a-i-b){
					s[k]=='?' ? cout<<'a' : cout<<s[k];
				}
				cout<<t;
				FOR(k, a-i, a){
					s[k]=='?' ? cout<<'a' : cout<<s[k];
				}
				cout<<'\n';
				return 0;
			}
		}
	}
	cout<<"UNRESTORABLE"<<'\n';
	return 0;
}
