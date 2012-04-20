#include <cstdio>

double dp[10001], prob[100];
int val[100];

int main() {
	int test, cs, n, i, j, m;
	double p, tmp;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lf %d", &p, &n);
		for(i = m = 0; i < n; i++) {
			scanf("%d %lf", val + i, prob + i);
			m += val[i];
		}
		for(dp[0] = 0.0, i = 1; i <= m; i++) dp[i] = 1.0;
		for(i = 0; i < n; i++) {
			for(j = m; j >= val[i]; j--) {
				tmp = dp[j - val[i]] + (1.0 - dp[j - val[i]]) * prob[i];
				if(dp[j] > tmp) dp[j] = tmp;
			}
		}
		for(j = m; j > 0; j--) if(dp[j] < p) break;
		printf("Case %d: %d\n", cs, j);
	}
	return 0;
}