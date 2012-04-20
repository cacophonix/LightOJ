#include <cstdio>
#include <cstring>

char vis[501][501];
double dp[501][501];

double solve(int r, int b) {
	if(r == 0) return (double)(b&1);
	if(b == 0) return (double)((r^1)&1);
	if(vis[r][b]) return dp[r][b];
	vis[r][b] = 1;
	double &ret = dp[r][b];
	if((r+b)&1) ret = 1.0 - (solve(r-1, b) * r + solve(r, b-1) * b) / (double)(r+b);
	else ret = 1.0 - solve(r, b-1);
	return ret;
}

int main() {
	int test, cs, r, b;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &r, &b);
		printf("Case %d: %.8lf\n", cs, solve(r, b) + 1e-10);
	}
	return 0;
}