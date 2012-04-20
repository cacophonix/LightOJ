#include <cstdio>

int weight[100], price[100];
int dp[10001];

int solve(int n, int C) {
	int i, j, tmp;
	for(i = 1; i <= C; i++) {
		dp[i] = dp[i-1];
		for(j = 0; j < n; j++) {
			if(i >= weight[j]) {
				tmp = dp[i-weight[j]]+price[j];
				if(tmp > dp[i]) dp[i] = tmp;
			}
		}
	}
	return dp[C];
}

int main() {
	int test, cs, n, w, i, cnt;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &w);
		for(i = 0; i < n; i++) {
			scanf("%d %d %d", &price[i], &cnt, &weight[i]);
			w -= weight[i] * cnt;
		}
		if(w < 0) printf("Case %d: Impossible\n", cs);
		else if(!w) printf("Case %d: 0\n", cs);
		else printf("Case %d: %d\n", cs, solve(n, w));
	}
	return 0;
}
