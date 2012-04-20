#include <cstdio>

typedef unsigned long long i64;

const int N = 25;
const int M = 150;

i64 dp[N][M], pow6[N];

i64 gcd(i64 a, i64 b) {
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}

int main() {
	int test, cs, i, n, j, k;
	i64 numer, denom, g;
	pow6[0] = 1;
	for(i = 1; i < N; i++) pow6[i] = pow6[i-1] * 6;
	for(i = 1; i <= 6; i++) dp[1][i] = 1;
	for(i = 2; i < N; i++)
		for(j = i*6; j >= i; j--)
			for(k = j-6 > 0? j-6 : 1; k < j; k++)
				dp[i][j] += dp[i-1][k];
	for(i = 1; i < N; i++)
		for(j = M-2; j >= 0; j--)
			dp[i][j] += dp[i][j+1];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &k);
		denom = pow6[n];
		numer = dp[n][k];
		g = gcd(numer, denom);
		numer /= g, denom /= g;
		if(denom == 1) printf("Case %d: %llu\n", cs, numer);
		else printf("Case %d: %llu/%llu\n", cs, numer, denom);
	}
	return 0;
}