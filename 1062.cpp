#include <cstdio>
#include <cmath>

const double EPS = 1e-9;
double x, y, c;

double find(double lo, double hi, int cnt) {
	double d, x1, h1, h2, c1;
	while(cnt--) {
		d = (lo + hi) / 2.0;
		h1 = sqrt(x * x - d * d);
		h2 = sqrt(y * y - d * d);
		c1 = h1 * h2 / (h1 + h2);
		if(c1 < c) hi = d;
		else lo = d;
	}
	return (lo + hi) / 2.0;
}

int main() {
	int test, cs;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lf %lf %lf", &x, &y, &c);
		printf("Case %d: %.8lf\n", cs, find(0, x < y? x:y, 32) + EPS);
	}
	return 0;
}
