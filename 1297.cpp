#include <cmath>
#include <cstdio>

int main() {
	int test, cs;
	double l, w, x, a, b, c;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lf %lf", &l, &w);
		a = 12.0, b = -4.0 * (l + w), c = l * w;
		x = (-b - sqrt(b*b - 4.0*a*c)) / (2.0 * a);
		printf("Case %d: %.8lf\n", cs, x * (2*x - l) * (2*x - w) + 1e-9);
	}
	return 0;
}