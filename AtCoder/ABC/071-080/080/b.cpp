#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int n, m, sum=0;
  cin>>n;
  m=n;
  for(;;){
    if(m==0) break;
    sum+=m%10;
    m/=10;
  }
  (n%sum==0) ? cout<<"Yes"<<endl : cout<<"No"<<endl;
  return 0;
}