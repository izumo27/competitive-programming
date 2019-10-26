#include <stdio.h>

int main() {
	int a,b,c;
	scanf("%d", &a);
	b = (a-(a%100))/100;
	c = a%10;
	if (b==c) printf("Yes\n");
	else printf("No\n");
	return 0;
}