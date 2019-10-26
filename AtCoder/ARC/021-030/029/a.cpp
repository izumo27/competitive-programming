#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	int t[10];
	cin>>n;
	for(int i=0; i<n; i++) cin>>t[i];
	int ans=810;
	for(int i=0; i<(1<<n); i++){
		int a=0, b=0;
		for(int j=0; j<n; j++){
			if((i>>j)&1) a+=t[j];
			else b+=t[j];
		}
		ans=min(ans, max(a, b));
	}
	cout<<ans<<endl;
	return 0;
}
