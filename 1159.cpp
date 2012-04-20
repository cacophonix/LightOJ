#include <cstdio>
#include <cstring>

#define max(a, b, c) ((a > b? (a > c? a : c) : (b > c? b : c)))

char s1[52], s2[52], s3[52];
int dp[52][52][52], len1, len2, len3;

int solve() {
	int i, j, k;
	for(i = 1; i <= len1; i++) {
		for(j = 1; j <= len2; j++) {
			for(k = 1; k <= len3; k++) {
				if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
					dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
				else
					dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]);
			}
		}
	}
	return dp[len1][len2][len3];
}

int main() {
	int test, cs;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%s %s %s", s1, s2, s3);
		len1 = strlen(s1);
		len2 = strlen(s2);
		len3 = strlen(s3);
		printf("Case %d: %d\n", cs, solve());
	}
	return 0;
}
