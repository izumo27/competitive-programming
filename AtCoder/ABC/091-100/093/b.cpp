#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int a, b, k, i;
  cin>>a>>b>>k;
  if((b-a+1)<2*k){
    for(i=a; i<=b; i++){
      cout<<i<<endl;
    }
  }
  else{
    for(i=0; i<k; i++){
      cout<<a+i<<endl;
    }
    for(i=0; i<k; i++){
      cout<<b-k+1+i<<endl;
    }
  }
  return 0;
}
