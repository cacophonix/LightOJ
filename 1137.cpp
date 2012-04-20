#include <cstdio>
#include <cmath>

const double EPS = 1e-10;
double a, c;

double find(double lo, double hi, int cnt) {
	double theta, r, a1;
	while(cnt--) {
		theta = (lo + hi) / 2.0;
		r = c / 2.0 / sin(theta);
		a1 = r * 2.0 * theta;
		if(a1 < a) lo = theta;
		else hi = theta;
	}
	return (lo + hi) / 2.0;
}

int main() {
	double L, n, C, r, x, theta;
	int test, cs;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lf %lf %lf", &L, &n, &C);
		a = (1.0 + n * C) * L; c = L;
		theta = find(0.0, acos(-1.0) / 2.0, 32);
		r = c / 2.0 / sin(theta);
		x = r - r * cos(theta);
		printf("Case %d: %.8lf\n", cs, x + EPS);
	}
	return 0;
}
