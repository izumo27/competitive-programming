#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int i, j;
	char c[10][10];
	for(i=0; i<3; i++){
		for(j=0; j<3; j++) cin>>c[i][j];
	}
	cout<<c[0][0]<<c[1][1]<<c[2][2]<<endl;
	return 0;
}
