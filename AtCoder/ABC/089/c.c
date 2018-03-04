#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
	int n, m = 0, i, j;
	long long int ans;
	scanf("%d", &n);
	char s[n][10];
	for (i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	long long int a[5]; // MARCHの数
	for (i = 0; i < 5; i++) {
		a[i] = 0;
	}
	for (i = 0; i < n; i++) {
		if (s[i][0] == 'M') a[0]++;
		else if (s[i][0] == 'A') a[1]++;
		else if (s[i][0] == 'R') a[2]++;
		else if (s[i][0] == 'C') a[3]++;
		else if (s[i][0] == 'H') a[4]++;
	}
	ans = a[0]*a[1]*a[2] + a[0]*a[1]*a[3] + a[0]*a[1]*a[4] + a[0]*a[2]*a[3] + a[0]*a[2]*a[4] + a[0]*a[3]*a[4] + a[1]*a[2]*a[3] + a[1]*a[2]*a[4] + a[1]*a[3]*a[4] + a[2]*a[3]*a[4];
	printf("%lld\n", ans);
	return 0;
}