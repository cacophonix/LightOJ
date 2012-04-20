#include <cstring>
#include <cstdio>

const int MOD = 100000007;

int dp[21][1001], coin[50], cnt[50];

int main() {
	int test, cs, n, i, j, k, c;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &k);
		for(i = 0; i < n; i++) scanf("%d", coin + i);
		for(i = 0; i < n; i++) scanf("%d", cnt + i);
		memset(dp, 0, sizeof dp); dp[0][0] = 1;
		for(i = 0; i < n; i++) {
			for(j = coin[i]; j <= k; j++) {
				for(c = 1; c <= cnt[i]; c++) {
					dp[c][j] += dp[c-1][j-coin[i]];
					if(dp[c][j] >= MOD) dp[c][j] %= MOD;
				}
			}
			for(j = coin[i]; j <= k; j++) {
				for(c = 1; c <= cnt[i]; c++) {
					dp[0][j] += dp[c][j];
					if(dp[0][j] >= MOD) dp[0][j] %= MOD;
					dp[c][j] = 0;
				}
			}
		}
		printf("Case %d: %d\n", cs, dp[0][k]);
	}
	return 0;
}
