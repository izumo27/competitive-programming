#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
	int n, m, i, j, a=0;
	cin>>n;
	string s[n];
	int ans[n];
	for(i=0; i<n; i++) ans[i]=0;
	for(i=0; i<n; i++) cin>>s[i];
	cin>>m;
	string t;
	for(i=0; i<m; i++){
		cin>>t;
		for(j=0; j<n; j++){
			if(t==s[j]) {
				s[j]="0";
				break;
			}
		}
	}
	for(i=0; i<n; i++){
		for(j=i; j<n; j++){
			if(s[i]==s[j] && s[i]!="0") ans[i]++;
		}
	}
	for(i=0; i<n; i++){
		if(a<ans[i]) a=ans[i];
	}
	cout<<a<<endl;
	return 0;
}