#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n, m;
	int a[100][100];
	cin>>n>>m;
	int x, y;
	for(int i=0; i<m; i++){
		cin>>x>>y;
		a[x-1][y-1]=a[y-1][x-1]=1;
	}
	int ans=0;
	for(int i=(1<<n)-1; i>0; i--){
		bool can=true;
		for(int j=0; j<n-1; j++){
			for(int k=j+1; k<n; k++){
				if(i>>j & i>>k & 1 && a[j][k]==0) can=false;
			}
		}
		int c=bitset<16>(i).count();
		if(can) ans=max(ans, c);
	}
	cout<<ans<<endl;
	return 0;
}
