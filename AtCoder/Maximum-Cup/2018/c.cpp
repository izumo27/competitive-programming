#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n, i, j, k, can;
	int a[110000];
	cin>>n;
	if(n%2){
		cout<<-1<<endl;
		return 0;
	}
	for(i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]==i){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(i=1; i<=n; i++){
		if(a[i]==0) continue;
		can=0;
		j=i;
		k=a[i];
		while(k!=i){
			k=a[j];
			a[j]=0;
			j=k;
			can++;
		}
		if(can%2){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<n/2<<endl;
	return 0;
}
