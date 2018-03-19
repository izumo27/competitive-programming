#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

bool comp(char a, char b){
	return a>b;
}

int main(){
	int i, sizes, sizet;
	string s, t;
	cin>>s>>t;
	sort(begin(s), end(s));
	sort(begin(t), end(t), comp);
	if(s<t) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}