#include <cstdio>
#include <cmath>

int main() {
	int test, cs;
	double ab, bc, ac, r;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &r);
		printf("Case %d: %.8lf\n", cs, sqrt(r/(r+1.0))*ab + 1e-10);
	}
	return 0;
}
