#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
	int n, k, i, ans=0;
	cin>>n>>k;
	int l[n];
	for(i=0; i<n; i++) cin>>l[i];
	sort(l, l+n, greater<int>());
	for(i=0; i<k; i++) ans+=l[i];
	cout<<ans<<endl;
	return 0;
}