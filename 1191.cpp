#include <cstdio>

typedef long long i64;

i64 barcode[51][51][51];

int main(){
	int test, cs, i, n, m, k;
	for(n = 1; n <= 50; n++) {
		for(barcode[n][1][n] = 1, k = 2; k <= n; k++) {
			for(m = n / k; m < n; m++) {
				for(i = n - m; i <= n - 1; i++) barcode[n][k][m] += barcode[i][k-1][m];
				for(i = 1; i <= m - 1; i++) barcode[n][k][m] += barcode[n-m][k-1][i];
			}
		}
	}
	for(n = 1; n <= 50; n++)
		for(k = 1; k <= n; k++)
			for(m = 2; m <= 50; m++)
				barcode[n][k][m] += barcode[n][k][m-1];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &n, &k, &m);
		printf("Case %d: %lld\n", cs, barcode[n][k][m]);
	}
	return 0;
}
