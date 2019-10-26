#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<n; ++i)

int h, w;
char c[514][514];
bool reached[514][514];
bool ok;

void dfs(int x, int y){
  if(c[x][y]=='#' || x<0 || x>=h || y<0 || y>=w) return;
  if(reached[x][y]) return;
  reached[x][y]=true;
  if(c[x][y]=='g'){
    ok=true;
    return;
  }
  c[x][y]='a';
  dfs(x-1, y);
  dfs(x+1, y);
  dfs(x, y-1);
  dfs(x, y+1);
}

int main(){
  scanf("%d%d", &h, &w);
  int a, b;
  REP(i, h){
    scanf("%s", c[i]);
  }
  REP(i, h){
    REP(j, w){
      if(c[i][j]=='s'){
          a=i;
          b=j;
      }
    }
  }
  dfs(a, b);
  ok ?  printf("Yes\n") : printf("No\n");
  return 0;
}
