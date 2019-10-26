#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #define int long long;

int main() {
  int i, j, d1, d2, d3, d4;
  int c[3][3];
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      scanf("%d", &c[i][j]);
    }
  }
  d1=c[0][1]-c[0][0];
  d2=c[0][2]-c[0][1];
  d3=c[1][0]-c[0][0];
  d4=c[2][0]-c[1][0];
  (c[1][1]-c[1][0]==d1 && c[2][1]-c[2][0]==d1 && c[1][2]-c[1][1]==d2 && c[2][2]-c[2][1]==d2 && c[1][1]-c[0][1]==d3 && c[1][2]-c[0][2]==d3 && c[2][1]-c[1][1]==d4 && c[2][2]-c[1][2]==d4) ? printf("Yes") : printf("No");
  return 0;
}