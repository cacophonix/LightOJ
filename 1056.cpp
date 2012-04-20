#include <cstdio>
#include <cmath>

const double eps = 1e-9;

int main() {
	double l, w, r, theta, x;
	int test, cs; char dump[2];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lf %s %lf", &l, dump, &w);
		r = sqrt(l*l + w*w) / 2.0;
		theta = 2.0 * asin(w/r/2.0);
		x = 200.0 / (r * theta + l);
		printf("Case %d: %.10lf %.10lf\n", cs, l*x+eps, w*x+eps);
	}
	return 0;
}
