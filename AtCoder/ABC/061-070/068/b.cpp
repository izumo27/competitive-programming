#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
	int n, i=6;
	cin>>n;
	int a[]={1,2,4,8,16,32,64};
	while(true){
		if(a[i]<=n){
			break;
		}
		i--;
	}
	cout<<a[i]<<endl;
	return 0;
}