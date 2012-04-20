#include <cstdio>
#include <cmath>

#define sq(x) ((x)*(x))
#define EPS 1e-9

typedef struct { double x, y; } Point;

Point a, b, c, d, e, f;

double calc(double k) {
	e.x = a.x + k * (b.x - a.x);
	e.y = a.y + k * (b.y - a.y);
	f.x = c.x + k * (d.x - c.x);
	f.y = c.y + k * (d.y - c.y);
	return sqrt(sq(e.x - f.x) + sq(e.y - f.y));
}

double ternary(double lo, double hi) {
	int d = 64;
	double lt, rt;
	while(d--) {
		lt = (2.0 * lo + hi) / 3.0;
		rt = (lo + 2.0 * hi) / 3.0;
		if(calc(lt) < calc(rt)) hi = rt;
		else lo = lt;
	}
	return (lo + hi) / 2.0;
}

int main() {
	int test, cs;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
		printf("Case %d: %.8lf\n", cs, calc(ternary(0.0, 1.0)) + EPS);
	}
	return 0;
}