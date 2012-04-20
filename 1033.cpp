#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int solve(char *s, int len) {
	int i, j, k, dp[2][128] = {{0}};
	for(i = 1; i <= len; i++) {
		for(j = 1, k = i&1; j <= len; j++) {
			if(s[i-1] == s[len-j]) dp[k][j] = 1 + dp[k^1][j-1];
			else dp[k][j] = max(dp[k][j-1], dp[k^1][j]);
		}
	}
	return len - dp[(i-1)&1][len];
}

int main() {
	int test, cs, len;
	char str[128];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%s", str);
		len = strlen(str);
		printf("Case %d: %d\n", cs, solve(str, len));
	}
	return 0;
}
