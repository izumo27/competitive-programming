#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n, m, x;
	int a[110];
	cin>>n>>m>>x;
	for(int i=0; i<m; i++) cin>>a[i];
	int cost1=0, cost2=0;
	for(int i=0; i<m; i++){
		if((a[i]-1)<x-1) cost1++;
		if((a[i]-1)>x-1) cost2++;
	}
	cout<<min(cost1, cost2)<<endl;
	return 0;
}
