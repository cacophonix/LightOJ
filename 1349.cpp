#include <cstdio>
#include <cstdlib>

typedef struct { int x, y, w; } Point;
typedef long long i64;

Point points[50000];

i64 f(int p, int n, int wh) {
	i64 ret = 0;
	for(int i = 0; i < n; i++) {
		if(wh) ret += (i64)points[i].w * abs(p - points[i].x);
		else ret += (i64) points[i].w * abs(p - points[i].y);
	}
	return ret;
}

int ternary(int lt, int rt, int n, int wh) {
	int d = 32, ltthrd, rtthrd;
	while(d--) {
		ltthrd = ((lt << 1) + rt) / 3;
		rtthrd = (lt + (rt << 1)) / 3;
		if(f(ltthrd, n, wh) < f(rtthrd, n, wh)) rt = rtthrd;
		else lt = ltthrd;
	}
	return (lt + rt) >> 1;
}

int main() {
	int test, cs, m, n, q, i;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &m, &n, &q);
		for(i = 0; i < q; i++) {
			scanf("%d %d %d", &points[i].x, &points[i].y, &points[i].w);
		}
		printf("Case %d: %d %d\n", cs, ternary(1, m, q, 1), ternary(1, n, q, 0));
	}
	return 0;
}