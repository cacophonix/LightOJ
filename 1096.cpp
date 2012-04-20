#include <cstdio>
#include <cstring>

#define MOD 10007

int base[4][4] = {{0,0,0,1},{1,0,0,0},{0,1,0,0},{0,0,0,1}};
int unit[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
int v[4] = {0,0,0,0};

void mul(int a[4][4], int b[4][4]) {
	int i, j, k, r[4][4] = {0};
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
			for(k = 0; k < 4; k++) {
				r[i][j] += a[i][k]*b[k][j];
				if(r[i][j] >= MOD) r[i][j] %= MOD;
			}
		}
	}
	memcpy(a, r, sizeof(r));
}

void expm(int r[4][4], int n) {
	int b[4][4];
	memcpy(r, unit, sizeof(unit));
	memcpy(b, base, sizeof(base));
	while(n > 0) {
		if(n&1) mul(r, b);
		n >>= 1;
		mul(b, b);
	}
}

int main() {
	int test, cs, res, n, i, mat[4][4];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d %d", &n, &base[0][0], &base[0][2], &v[3]);
		if(n <= 2) printf("Case %d: 0\n", cs);
		else {
			expm(mat, n-2);
			for(i = res = 0; i < 4; i++) {
				res += mat[0][i] * v[i];
				if(res >= MOD) res %= MOD;
			}
			printf("Case %d: %d\n", cs, res);
		}
	}
	return 0;
}
