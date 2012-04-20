#include <cstdio>

#define calc(n) (n/3*2+(n%3==2))

int main() {
	int a, b, cs, test;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &a, &b); a--;
		printf("Case %d: %d\n", cs, calc(b) - calc(a));
	}
	return 0;
}
