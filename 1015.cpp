#include <cstdio>

int main() {
	int test, cs, n, a, s;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n); s = 0;
		while(n--) {
			scanf("%d", &a);
			if(a > 0) s += a;
		}
		printf("Case %d: %d\n", cs, s);
	}
	return 0;
}
