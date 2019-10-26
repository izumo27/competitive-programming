#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int a, b, c, d, e, f, i, j, k, l, water, suger, ans1=100, ans2=0;
	cin>>a>>b>>c>>d>>e>>f;
	a*=100;
	b*=100;
	for(i=0; a*i<=f; i++){
		for(j=0; a*i+b*j<=f; j++){
			for(k=0; a*i+b*j+c*k<=f; k++){
				for(l=0; a*i+b*j+c*k+d*l<=f; l++){
					water=a*i+b*j;
					suger=c*k+d*l;
					if(100*suger<=e*water && suger*(ans1)>=ans2*(water+suger)){
						ans1=water+suger;
						ans2=suger;
					}
				}
			}
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}