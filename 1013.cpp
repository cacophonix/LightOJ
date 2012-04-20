#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long i64;

const int MAX = 32;

char str1[MAX], str2[MAX];
int len1, len2;
int dp[MAX][MAX];
i64 dp2[MAX][MAX];

int solve() {
	int i, j;
	for(i = 1; i <= len1; i++) {
		for(j = 1; j <= len2; j++) {
			if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[len1][len2];
}

i64 solve2() {
	int i, j;
	for(i = 1; i <= len1; i++) {
		for(j = 1; j <= len2; j++) {
			dp2[i][j] = 0;
			if(str1[i-1] == str2[j-1]) dp2[i][j] += dp2[i-1][j-1];
			else {
				if(dp[i-1][j] + 1 == dp[i][j]) dp2[i][j] += dp2[i-1][j];
				if(dp[i][j-1] + 1 == dp[i][j]) dp2[i][j] += dp2[i][j-1];
			}
		}
	}
	return dp2[len1][len2];
}

int main() {
	int test, cs, ret, i, j; i64 ret1;
	for(i = 0; i < MAX; i++) dp[i][0] = i, dp2[i][0] = 1;
	for(j = 0; j < MAX; j++) dp[0][j] = j, dp2[0][j] = 1;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%s %s", str1, str2);
		len1 = strlen(str1); len2 = strlen(str2);
		ret = solve(); ret1 = solve2();
		printf("Case %d: %d %lld\n", cs, ret, ret1);
	}
	return 0;
}
