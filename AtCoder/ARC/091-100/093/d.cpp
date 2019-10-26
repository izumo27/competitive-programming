#include <bits/stdc++.h>
using namespace std;
typedef long long int llint;

int main(){
  int a, b, h=100, w=100, i, j;
  char s[110][110];
  cin>>a>>b;
  a--;
  b--;
  cout<<h<<' '<<w<<endl;
  for(i=0; i<50; i++){
    for(j=0; j<100; j++){
      s[i][j]='#';
    }
  }
  for(i=50; i<100; i++){
    for(j=0; j<100; j++){
      s[i][j]='.';
    }
  }
  for(i=0; i<50 && a; i+=2){
    for(j=0; j<100 && a; j+=2){
      s[i][j]='.';
      a--;
    }
  }
  for(i=99; i>50 && b; i-=2){
    for(j=0; j<100 && b; j+=2){
      s[i][j]='#';
      b--;
    }
  }
  for(i=0; i<h; i++){
    for(j=0; j<w; j++){
      cout<<s[i][j];
    }
    cout<<endl;
  }
  return 0;
}