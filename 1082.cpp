#include <cstdio>

int dp[1<<17][17], a[1<<17];

void process(int n) {
	int i, j;
	for(i = 0; i < n; i++) dp[i][0] = i;
	for(j = 1; (1 << j) <= n; j++) {
		for(i = 0; i + (1 << j) - 1 < n; i++) {
			if(a[dp[i][j - 1]] < a[dp[i + (1 << (j - 1))][j - 1]]) dp[i][j] = dp[i][j - 1];
			else dp[i][j] = dp[i + (1 << (j - 1))][j - 1];
		}
	}
}

int main() {
	int test, cs, n, q, i, j, k;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &q);
		for(i = 0; i < n; i++) scanf("%d", a + i);
		process(n); printf("Case %d:\n", cs);
		while(q--) {
			scanf("%d %d", &i, &j); i--; j--;
			for(k = 0; (1<<k) <= (j-i+1); k++); k--;
			if(a[dp[i][k]] <= a[dp[j - (1<<k) + 1][k]]) printf("%d\n", a[dp[i][k]]);
			else printf("%d\n", a[dp[j - (1<<k) + 1][k]]);
		}
	}
	return 0;
}
