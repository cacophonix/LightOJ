#include <cstring>
#include <cstdio>

const int MOD = 100000007;

int dp[10001], coin[100];

int main() {
	int test, cs, n, i, j, k, c;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &k);
		for(i = 0; i < n; i++) scanf("%d", coin + i);
		memset(dp, 0, sizeof dp); dp[0] = 1;
		for(i = 0; i < n; i++) {
			for(j = coin[i]; j <= k; j++) {
				dp[j] += dp[j-coin[i]];
				if(dp[j] >= MOD) dp[j] %= MOD;
			}
		}
		printf("Case %d: %d\n", cs, dp[k]);
	}
	return 0;
}
