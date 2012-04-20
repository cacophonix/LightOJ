#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int dp[101][101];
string pre[101][101];
char s1[101], s2[101];
int len1, len2;

int solve() {
	int i, j;
	for(i = 1; i <= len1; i++) {
		for(j = 1; j <= len2; j++) {
			if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1], pre[i][j] = pre[i-1][j-1]+s1[i-1];
			else if(dp[i-1][j] > dp[i][j-1]) dp[i][j] = dp[i-1][j], pre[i][j] = pre[i-1][j];
			else if(dp[i-1][j] < dp[i][j-1]) dp[i][j] = dp[i][j-1], pre[i][j] = pre[i][j-1];
			else dp[i][j] = dp[i-1][j], pre[i][j] = min(pre[i-1][j], pre[i][j-1]);
		}
	}
	return dp[len1][len2];
}

int main() {
	int test, cs, lcs;
	scanf("%d", &test);
	for(int i = 0; i < 101; i++) pre[i][0] = pre[0][i] = "";
	for(cs = 1; cs <= test; cs++) {
		scanf("%s %s", s1,s2);
		len1 = strlen(s1); len2 = strlen(s2);
		lcs = solve();
		if(!lcs) printf("Case %d: :(\n", cs);
		else printf("Case %d: %s\n", cs, pre[len1][len2].c_str());
	}
	return 0;
}
