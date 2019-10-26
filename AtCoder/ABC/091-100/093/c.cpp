#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int x, y;
  int a[10];
  cin>>a[0]>>a[1]>>a[2];
  sort(a, a+3);
  x=a[2]-a[0];
  y=a[2]-a[1];
  if(x%2==0 && y%2==0){
    cout<<x/2+y/2<<endl;
    return 0;
  }
  if(x%2==0 || y%2==0){
    cout<<(x+1)/2+(y+1)/2+1<<endl;
    return 0;
  }
  else{
    cout<<x/2+y/2+1<<endl;
    return 0;
  }
}
