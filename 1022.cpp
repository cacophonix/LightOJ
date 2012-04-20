#include <cstdio>
#include <cmath>

int main() {
	double eps = 1e-9, pi = acos(-1.0), r, rs;
	int test, cs = 1;
	scanf("%d", &test);
	while(test--) {
		scanf("%lf", &r); rs = r*r;
		printf("Case %d: %.2lf\n", cs++, 4.0*rs - pi*rs + eps);
	}
	return 0;
}
