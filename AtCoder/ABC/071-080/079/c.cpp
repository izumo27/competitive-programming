#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int x, i;
	int a[10];
	cin>>x;
	for(i=3; i>=0; i--){
		a[i]=x%10;
		x/=10;
	}
	if(a[0]+a[1]+a[2]+a[3]==7) cout<<a[0]<<'+'<<a[1]<<'+'<<a[2]<<'+'<<a[3]<<"=7"<<endl;
	else if(a[0]-a[1]+a[2]+a[3]==7) cout<<a[0]<<'-'<<a[1]<<'+'<<a[2]<<'+'<<a[3]<<"=7"<<endl;
	else if(a[0]+a[1]-a[2]+a[3]==7) cout<<a[0]<<'+'<<a[1]<<'-'<<a[2]<<'+'<<a[3]<<"=7"<<endl;
	else if(a[0]+a[1]+a[2]-a[3]==7) cout<<a[0]<<'+'<<a[1]<<'+'<<a[2]<<'-'<<a[3]<<"=7"<<endl;
	else if(a[0]-a[1]-a[2]+a[3]==7) cout<<a[0]<<'-'<<a[1]<<'-'<<a[2]<<'+'<<a[3]<<"=7"<<endl;
	else if(a[0]-a[1]+a[2]-a[3]==7) cout<<a[0]<<'-'<<a[1]<<'+'<<a[2]<<'-'<<a[3]<<"=7"<<endl;
	else if(a[0]+a[1]-a[2]-a[3]==7) cout<<a[0]<<'+'<<a[1]<<'-'<<a[2]<<'-'<<a[3]<<"=7"<<endl;
	else if(a[0]-a[1]-a[2]-a[3]==7) cout<<a[0]<<'-'<<a[1]<<'-'<<a[2]<<'-'<<a[3]<<"=7"<<endl;
	return 0;
}
