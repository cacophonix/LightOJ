#include <cstdio>

int main() {
	int test, cs, n, i;
	double ex;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 1, ex = 0.0; i <= n; i++) ex += (double) n / i;
		printf("Case %d: %.8lf\n", cs, ex + 1e-10);
	}
	return 0;
}
