#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef unsigned long long i64;

i64 base[2][2] = {{0, 0}, {1, 0}}, unit[2][2] = {{1, 0}, {0, 1}};

void mul(i64 a[2][2], i64 b[2][2]) {
	i64 r[2][2];
	int i, j, k;
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			for(k = 0, r[i][j] = 0; k < 2; k++)
				r[i][j] += a[i][k] * b[k][j];
	memcpy(a, r, sizeof(r));
}

void modexp(i64 r[2][2], int p) {
	i64 b[2][2];
	memcpy(b, base, sizeof(base));
	memcpy(r, unit, sizeof(unit));
	while(p > 0) {
		if(p & 1) mul(r, b);
		p >>= 1;
		mul(b, b);
	}
}

int main() {
	int test, n, cs;
	i64 p, q, ret, r[2][2];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%llu %llu %d", &p, &q, &n);
		base[0][0] = p, base[0][1] = -q;
		if(n == 0) printf("Case %d: 2\n", cs);
		else if(n == 1) printf("Case %d: %llu\n", cs, p);
		else {
			modexp(r, n-1);
			ret = r[0][0] * p + r[0][1] * 2;
			printf("Case %d: %llu\n", cs, ret);
		}
	}
	return 0;
}
