#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
	int n, l, i;
	string s[110];
	cin>>n>>l;
	for(i=0; i<n; i++) cin>>s[i];
	sort(s, s+n);
	for(i=0; i<n; i++) cout<<s[i];
	cout<<endl;
	return 0;
}