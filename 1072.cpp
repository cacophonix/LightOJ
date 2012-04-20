#include <cstdio>
#include <cmath>

int main() {
	int test, cs;
	double r, R, n, th;
	double eps = 1e-12, pi = acos(-1.0);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lf %lf", &R, &n);
		th = pi / n;
		printf("Case %d: %.10lf\n", cs, R - R / (1 + sin(th)) + eps);
	}
	return 0;
}
