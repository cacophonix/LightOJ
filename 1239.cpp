#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long i64;
typedef struct { i64 x, y; } point;

const int MAX = 50005;

point P[MAX], C[MAX], P0;

inline i64 triArea2(const point &a, const point &b, const point &c) {
	return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

inline i64 sqDist(const point &a, const point &b) {
	return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

inline bool comp(const point &a, const point &b) {
	i64 d = triArea2(P0, a, b);
	if(d < 0) return false;
	if(!d && sqDist(P0, a) > sqDist(P0, b)) return false;
	return true;
}

void convexHull(int &np, int &nc) {
	int i, j, pos = 0;
	for(i = 1; i < np; i++)
		if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x))
			pos = i;
	swap(P[0], P[pos]);
	P0 = P[0];
	sort(&P[1], &P[np], comp);
	for(i = 0; i < 3; i++) C[i] = P[i];
	for(i = j = 3; i < np; i++) {
		while(triArea2(C[j-2], C[j-1], P[i]) < 0) j--;
		C[j++] = P[i];
	}
	nc = j;
}

int main() {
	int test, cs, nc, np, i;
	double perim, d, pi = acos(-1.0), eps = 1e-9;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %lf", &np, &d);
		for(i = 0; i < np; i++) scanf("%lld %lld", &P[i].x, &P[i].y);
		if(np < 3) perim = 2.0 * sqrt((double)sqDist(P[0], P[1])) + 2.0 * pi * d;
		else {
			convexHull(np, nc);
			C[nc] = C[0]; perim = 0.0;
			for(i = 0; i < nc; i++) perim += sqrt((double)sqDist(C[i], C[i+1]));
			perim += 2.0 * pi * d;
		}
		printf("Case %d: %.8lf\n", cs, perim + eps);
	}
	return 0;
}
