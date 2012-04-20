#include <cstdio>
#include <cmath>

#define sq(x) ((x)*(x))
#define min(a, b) ((a)<(b)?(a):(b))

double polyArea2(int *x, int *y, int n) {
	double area = 0.0;
	for(int i = 0, j = n-1; i < 3; j = i++) area += x[j]*y[i] - y[j] * x[i];
	if(area < 0) area = -area;
	return area;
}

double distsq(int x1, int y1, int x2, int y2, int x3, int y3) {
	double bc = sq(x1 - x2) + sq(y1 - y2);
	double ab = sq(x1 - x3) + sq(y1 - y3);
	double ac = sq(x2 - x3) + sq(y2 - y3);
	int x[3] = {x1, x2, x3}, y[3] = {y1, y2, y3};
	double p2 = polyArea2(x, y, 3);
	double ax = sq(p2) / bc;
	if(ab - ax > bc || ac - ax > bc) ax = min(ab, ac);
	return ax;
}

double seg2segdistsq(int *x1, int *y1, int *x2, int *y2) {
	double d1 = distsq(x1[0], y1[0], x1[1], y1[1], x2[0], y2[0]);
	double d2 = distsq(x1[0], y1[0], x1[1], y1[1], x2[1], y2[1]);
	double d3 = distsq(x2[0], y2[0], x2[1], y2[1], x1[0], y1[0]);
	double d4 = distsq(x2[0], y2[0], x2[1], y2[1], x1[1], y1[1]);
	return min(min(d1, d2), min(d3, d4));
}

int main() {
	int test, cs, i, j, m, n;
	int mx[128], my[128], nx[128], ny[128];
	double res, eps = 1e-9;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &m);
		for(i = 0; i < m; i++) scanf("%d %d", &mx[i], &my[i]);
		mx[m] = mx[0], my[m] = my[0];
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d %d", &nx[i], &ny[i]);
		nx[n] = nx[0], ny[n] = ny[0];
		res = 1e19;
		for(i = 0; i < m; i++) {
			for(j = 0; j < n; j++) {
				int x1[] = {mx[i], mx[i+1]};
				int y1[] = {my[i], my[i+1]};
				int x2[] = {nx[j], nx[j+1]};
				int y2[] = {ny[j], ny[j+1]};
				res = min(res, seg2segdistsq(x1, y1, x2, y2));
			}
		}
		res = sqrt(res) / 2.0;
		printf("Case %d: %.8lf\n", cs, res + eps);
	}
	return 0;
}
