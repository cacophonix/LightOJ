#include <cstdio>
#include <cstring>
using namespace std;

int unit[6][6] = {{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};
int base[6][6] = {{0,0,0,0,0,0},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,0,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0}};

void mul(int a[6][6], int b[6][6], int m) {
	int i, j, k, r[6][6];
	for(i = 0; i < 6; i++) {
		for(j = 0; j < 6; j++) {
			for(k = r[i][j] = 0; k < 6; k++) {
				r[i][j] += a[i][k] * b[k][j];
				if(r[i][j] >= m) r[i][j] %= m;
			}
		}
	}
	memcpy(a, r, sizeof r);
}

void exp(int r[6][6], int p, int m) {
	int b[6][6];
	memcpy(r, unit, sizeof unit);
	memcpy(b, base, sizeof base);
	while(p > 0) {
		if(p & 1) mul(r, b, m);
		p >>= 1;
		mul(b, b, m);
	}
}

int main() {
	int test, cs, n, q, f[3], g[3], m, i, retf, retg;
	int *a1[3], *a2[3], r[6][6];
	a1[0] = &base[0][0], a1[1] = &base[0][1], a1[2] = &base[0][5];
	a2[0] = &base[3][3], a2[1] = &base[3][4], a2[2] = &base[3][2];
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		printf("Case %d:\n", cs);
		scanf("%d %d %d", a1[0], a1[1], a1[2]);
		scanf("%d %d %d", a2[0], a2[1], a2[2]);
		scanf("%d %d %d", &f[0], &f[1], &f[2]);
		scanf("%d %d %d", &g[0], &g[1], &g[2]);
		scanf("%d %d", &m, &q);
		for(i = 0; i < 3; i++) {
			if(f[i] >= m) f[i] %= m;
			if(g[i] >= m) g[i] %= m;
			if(*a1[i] >= m) *a1[i] %= m;
			if(*a2[i] >= m) *a2[i] %= m;
		}
		while(q--) {
			scanf("%d", &n);
			if(m == 1) printf("0 0\n");
			else if(n < 3) printf("%d %d\n", f[n], g[n]);
			else {
				exp(r, n-2, m);
				retf = r[0][0] * f[2] + r[0][1] * f[1] + r[0][2] * f[0];
				if(retf >= m) retf %= m;
				retf += r[0][3] * g[2] + r[0][4] * g[1] + r[0][5] * g[0];
				if(retf >= m) retf %= m;
				retg = r[3][0] * f[2] + r[3][1] * f[1] + r[3][2] * f[0];
				if(retg >= m) retg %= m;
				retg += r[3][3] * g[2] + r[3][4] * g[1] + r[3][5] * g[0];
				if(retg >= m) retg %= m;
				printf("%d %d\n", retf, retg);
			}
		}
	}
	return 0;
}