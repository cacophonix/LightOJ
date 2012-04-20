#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1024;

int dp[2][MAX], tm[2][MAX], ex[2][MAX];

int main() {
	int test, cs, i, j, n;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < 2; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &tm[i][j]);
		for(i = 0; i < 2; i++)
			for(j = 1; j < n; j++)
				scanf("%d", &ex[i][j]);
		dp[0][0] = tm[0][0], dp[1][0] = tm[1][0];
		for(i = 1; i < n; i++)
			for(j = 0; j < 2; j++)
				dp[j][i] = tm[j][i] + min(dp[j][i-1], dp[j^1][i-1] + ex[j^1][i]);
		printf("Case %d: %d\n", cs, min(dp[0][n-1], dp[1][n-1]));
	}
	return 0;
}