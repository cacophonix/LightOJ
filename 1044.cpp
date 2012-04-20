#include <cstdio>
#include <cstring>

const int MAX = 1000;

int test, cs;
int palin[MAX][MAX], deg[MAX], dp[MAX+1];
char str[MAX + 1];

int calc(int n) {
	int i, j, k;
	memset(deg, 0, sizeof(int) * n);
	for(k = 0; k < n; k++) {
		for(i = k, j = k + 1; i >= 0 && j < n && str[i] == str[j]; i--, j++) palin[i][deg[i]++] = j;
		for(i = j = k; i >= 0 && j < n && str[i] == str[j]; i--, j++) palin[i][deg[i]++] = j;
	}
	for(k = n-1, dp[n] = 0; k >= 0; k--) {
		dp[k] = 0x3f3f3f3f;
		for(i = 0; i < deg[k]; i++) if(dp[k] > 1 + dp[palin[k][i]+1]) dp[k] = 1 + dp[palin[k][i]+1];
	}
	return dp[0];
}

int main() {
	int test, cs;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%s", str);
		printf("Case %d: %d\n", cs, calc(strlen(str)));
	}
	return 0;
}