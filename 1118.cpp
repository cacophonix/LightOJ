#include <cstdio>
#include <cmath>

struct Point { int x, y; };
struct Circle { Point c; int r; };

double pi, eps;

inline int sq(int x) { return x*x; }

inline int sqDist(const Point &a, const Point &b) {
	return sq(a.x-b.x) + sq(a.y-b.y);
}

inline double commonArea(const Circle &a, const Circle &b) {
	int dsq = sqDist(a.c, b.c);
	double d = sqrt((double)dsq);
	if(sq(a.r + b.r) <= dsq) return 0;
	if(a.r >= b.r && sq(a.r-b.r) >= dsq) return pi * b.r * b.r;
	if(a.r <= b.r && sq(b.r-a.r) >= dsq) return pi * a.r * a.r;
	double angleA = 2.0 * acos((a.r * a.r + dsq - b.r * b.r) / (2.0 * a.r * d));
	double angleB = 2.0 * acos((b.r * b.r + dsq - a.r * a.r) / (2.0 * b.r * d));
	return 0.5 * (a.r * a.r * (angleA - sin(angleA)) + b.r * b.r * (angleB - sin(angleB)));
}

int main() {
	int test, cs;
	Circle a, b;
	pi = acos(-1.0);
	eps = 1e-10;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d %d %d %d", &a.c.x, &a.c.y, &a.r, &b.c.x, &b.c.y, &b.r);
		printf("Case %d: %.8lf\n", cs, commonArea(a, b) + eps);
	}
	return 0;
}