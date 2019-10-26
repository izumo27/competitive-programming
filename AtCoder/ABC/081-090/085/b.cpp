#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
	int n, i, ans=0;
	int d[110], num[110]={};
	cin>>n;
	for(i=0; i<n; i++) cin>>d[i];
	for(i=0; i<n; i++) num[d[i]]++;
	for(i=1; i<=100; i++){
		if(num[i]>0) ans++;
	}
	cout<<ans<<endl;
	return 0;
}