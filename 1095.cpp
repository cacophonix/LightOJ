#include <cstdio>

typedef long long i64;

const int MAX = 1001, MOD = 1000000007;

i64 nCr[MAX][MAX], fact[MAX];

int main() {
	int test, cs, i, n, m, k;
	i64 res;
	fact[0] = nCr[0][0] = 1;
	for(i = 1; i < MAX; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		nCr[i][0] = nCr[i][i] = 1;
	}
	for(i = 1; i < MAX; i++)
		for(k = 1; k < i; k++)
			nCr[i][k] = (nCr[i-1][k] + nCr[i-1][k-1]) % MOD;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &n, &m, &k);
		for(res = 0, i = 0; i <= m-k; i++) {
			if(i & 1) res = (res - nCr[m-k][i] * fact[n - k - i]) % MOD;
			else res = (res + nCr[m-k][i] * fact[n - k - i]) % MOD;
		}
		res = (res * nCr[m][k]) % MOD;
		if(res < 0) res += MOD;
		printf("Case %d: %lld\n", cs, res);
	}
	return 0;
}