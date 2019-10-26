#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, i;
  ll a[100010];
  ll sum, ans, sum2, ans2;
  bool sign;
  cin>>n;
  for(i=0; i<n; i++) cin>>a[i];
  // s0>0
  sign=true;
  if(a[0]>0){
    ans=0;
    sum=a[0];
  }
  else{
    ans=1-a[0];
    sum=1;
  }
  for(i=1; i<n; i++){
    sign=!sign;
    if(sign){
      if(sum+a[i]>0) sum+=a[i];
      else{
        ans+=1-(sum+a[i]);
        sum=1;
      }
    }
    else{
      if(sum+a[i]<0) sum+=a[i];
      else{
        ans+=1+(sum+a[i]);
        sum=-1;
      }
    }
  }
  // s0<0
  sign=false;
  if(a[0]<0){
    ans2=0;
    sum2=a[0];
  }
  else{
    ans2=1+a[0];
    sum2=-1;
  }
  for(i=1; i<n; i++){
    sign=!sign;
    if(sign){
      if(sum2+a[i]>0) sum2+=a[i];
      else{
        ans2+=1-(sum2+a[i]);
        sum2=1;
      }
    }
    else{
      if(sum2+a[i]<0) sum2+=a[i];
      else{
        ans2+=1+(sum2+a[i]);
        sum2=-1;
      }
    }
  }
  cout<<min(ans, ans2)<<endl;
  return 0;
}