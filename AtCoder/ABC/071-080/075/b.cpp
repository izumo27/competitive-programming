#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int h, w, i, j, k, x, y, ans;
  string s[60];
  int dx[]={-1, 0, 1, -1, 0, 1, -1, 0, 1};
  int dy[]={-1, -1, -1, 0, 0, 0, 1, 1, 1};
  cin>>h>>w;
  for(i=0; i<h; i++) cin>>s[i];
  for(i=0; i<h; i++){
    for(j=0; j<w; j++){
      if(s[i][j]=='#') continue;
      ans=0;
      for(k=0; k<9; k++){
        x=i+dx[k];
        y=j+dy[k];
        if(x<0 || x>=h) continue;
        if(y<0 || y>=w) continue;
        if(s[x][y]=='#') ans++;
      }
      s[i][j]=char('0'+ans);
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