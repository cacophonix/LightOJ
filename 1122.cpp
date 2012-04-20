#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
	int n, m, a[10], dp[11][10], test, cs, i, j, k;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &m, &n);
		for(i = 0; i < m; i++) {
			scanf("%d", &a[i]);
			dp[1][i] = 1;
		}
		for(i = 2; i <= n; i++) {
			for(j = 0; j < m; j++) {
				dp[i][j] = 0;
				for(k = 0; k < m; k++) {
					if(abs(a[j]-a[k]) <= 2) dp[i][j] += dp[i-1][k];
				}
			}
		}
		for(k = i = 0; i < m; i++) k += dp[n][i];
		printf("Case %d: %d\n", cs, k);
	}
	return 0;
}
