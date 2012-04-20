#include <cstdio>
#include <cstring>

int base[2][2] = {{1, 1}, {1, 0}}, unit[2][2] = {{1, 0}, {0, 1}};
int mod[5] = {1, 10, 100, 1000, 10000}, m;

void mul(int a[2][2], int b[2][2]) {
	int i, j, k, r[2][2];
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			for(r[i][j] = k = 0; k < 2; k++) {
				r[i][j] += a[i][k] * b[k][j];
				if(r[i][j] >= mod[m]) r[i][j] %= mod[m];
			}
		}
	}
	memcpy(a, r, sizeof r);
}

void exp(int r[2][2], int n) {
	int b[2][2];
	memcpy(r, unit, sizeof unit);
	memcpy(b, base, sizeof base);
	while(n > 0) {
		if(n & 1) mul(r, b);
		n >>= 1;
		mul(b, b);
	}
}

int main() {
	int test, cs, n, r[2][2], a[2];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d %d", &a[1], &a[0], &n, &m);
		if(n < 2) printf("Case %d: %d\n", cs, a[n] % mod[m]);
		else {
			exp(r, n - 1);
			printf("Case %d: %d\n", cs, (r[0][0] * a[0] + r[0][1] * a[1]) % mod[m]);
		}
	}
	return 0;
}