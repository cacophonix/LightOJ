#include <cstdio>

int main() {
	int test, cs, n, i, b;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; !(n & (1<<i)); i++);
		for(b = -1; n & (1<<i); i++, b++);
		n >>= i; n |= 1; n <<= i; n |= ((1 << b)-1);
		printf("Case %d: %d\n", cs, n);
	}
	return 0;
}
