#include <cstdio>
#include <cstring>

typedef long long i64;

char s[64];
i64 dp[64][64];

i64 solve(int i, int j) {
	if(i > j) return 1;
	if(dp[i][j] != -1) return dp[i][j];
	i64 &ret = dp[i][j]; ret = 0;
	if(s[i] == s[j]) ret += 1 + solve(i+1, j-1);
	ret += solve(i+1, j) + solve(i, j-1) - solve(i+1, j-1);
	return ret;
}

int main() {
	int test, cs;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%s", s);
		memset(dp, -1, sizeof dp);
		printf("Case %d: %lld\n", cs, solve(0, strlen(s)-1) >> 1);
	}
	return 0;
}
