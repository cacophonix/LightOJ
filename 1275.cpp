#include <cstdio>

#define f(t) ((t) * (c - (t) * n))

int main() {
	int test, cs, n, c, tf, tc;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &c);
		if(!n) printf("Case %d: 0\n", cs);
		else {
			tf = c / (n << 1);
			tc = (c % (n << 1)) ? tf + 1 : tf;
			printf("Case %d: %d\n", cs, f(tf) >= f(tc) ? tf : tc);
		}
	}
	return 0;
}