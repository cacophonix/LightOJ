#include <cstdio>

const int MOD = 10056;
const int MAX = 1000;

#define min(a, b) ((a)<(b)?(a):(b))

int nCr[MAX + 1][(MAX>>1) + 1], f[MAX + 1];

void C() {
	int i, j;
	nCr[0][0] = nCr[1][0] = 1;
	for(i = 2; i <= MAX; i++) {
		nCr[i][0] = 1;
		for(j = 1; j <= (i >> 1); j++) {
			nCr[i][j] = nCr[i-1][min(j, i-1-j)] + nCr[i-1][min(j-1, i-j)];
			if(nCr[i][j] >= MOD) nCr[i][j] -= MOD;
		}
	}
}

void F() {
	int i, k;
	f[0] = f[1] = 1;
	for(i = 2; i <= MAX; i++) {
		f[i] = 0;
		for(k = 1; k <= i; k++) {
			f[i] = f[i] + nCr[i][min(k, i-k)] * f[i - k];
			if(f[i] >= MOD) f[i] %= MOD;
		}
	}
}

int main() {
	int cs, test, n;
	C(); F();
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		printf("Case %d: %d\n", cs, f[n]);
	}
	return 0;
}