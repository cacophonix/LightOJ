#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 100009
#define ld double
#define i64 long long

typedef struct { i64 x, y; } point;

point P[MAX], C[MAX], P0;
ld pi, eps = 1e-9;

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

inline bool normal(const point &a, const point &b) {
	return ((a.x==b.x) ? a.y < b.y : a.x < b.x);
}

inline bool issame(const point &a, const point &b) {
	return (a.x == b.x && a.y == b.y);
}

inline void makeUnique(int &np) {
	sort(&P[0], &P[np], normal);
	np = unique(&P[0], &P[np], issame) - P;
}

inline void convexHull(int &np, int &nc) {
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

inline void compress(int &nc) {
	int i, j;
	C[nc] = C[0];
	for(i=j=1; i < nc; i++) {
		if(triArea2(C[j-1], C[i], C[i+1])) C[j++] = C[i];
	}
	nc = j;
}

inline void correctColinear(int np, int &nc) {
	for(int i = np - 2; i > 0; i--) {
		if(!triArea2(C[nc-1], P[i], C[0])) C[nc++] = P[i];
		else break;
	}
}

inline ld angle(const point &o, const point &a, const point &b) {
	point t1, t2;
	ld theta;
	t1.x = a.x - o.x, t1.y = a.y - o.y;
	t2.x = b.x - o.x, t2.y = b.y - o.y;
	theta = atan2((ld)t2.y, (ld)t2.x) - atan2((ld)t1.y, (ld)t1.x);
	if(theta < -eps) theta += 2.0 * pi;
	return theta;
}

int main() {
	int test, cs = 1, i, np, nc;
	ld diff, mndiff;
	pi = acos(-1.0);
	freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &np);
		for(i = 0; i < np; i++) scanf("%lld %lld", &P[i].x, &P[i].y);
		makeUnique(np);
		if(np < 3) { printf("Case %d: %.8lf\n", cs++, eps); continue; }
		else {
			convexHull(np, nc);
			compress(nc);
			if(nc < 3) { printf("Case %d: %.8lf\n", cs++, eps); continue; }
			else {
				mndiff = angle(C[0], C[1], C[nc-1]);
				C[nc] = C[0];
				for(i = 1; i < nc; i++) {
					diff = angle(C[i], C[i+1], C[i-1]);
					if(diff + eps < mndiff) mndiff = diff;
				}
			}
			printf("Case %d: %.8lf\n", cs++, eps + mndiff*180.0/pi);
		}
	}
	return 0;
}
