#include <cstdio>
#include <cmath>

double tarea(double a, double b, double c) {
	double s = (a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
	int test, cs;
	double a, b, c, d, h, area, diff;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		diff = fabs(a - c);
		area = tarea(d, diff, b);
		h = 2.0 * area / diff;
		printf("Case %d: %.8lf\n", cs, 0.5 * h * (a + c) + (1e-10));
	}
	return 0;
}
