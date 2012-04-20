#include <cstdio>
#include <algorithm>
using namespace std;

int dp[200][100][100], f[200][100][100], grid[100][100];
int test, cs, R, C;

int solve(int stp, int r1, int r2) {
	if(stp == R + C - 2) {
		if(stp-r1==C-1 && r1==R-1 && r1==r2) return grid[r1][stp-r1];
		else return -1;
	}
	if(f[stp][r1][r2] == cs) return dp[stp][r1][r2];
	f[stp][r1][r2] = cs;
	int &ret = dp[stp][r1][r2]; ret = -1;
	int c1 = stp - r1, c2 = stp - r2;
	if(c1 < C && c2 < C) {
		ret = max(ret, solve(stp + 1, r1, r2));
		if(r1 + 1 < R) ret = max(ret, solve(stp + 1, r1 + 1, r2));
		if(r2 + 1 < R) ret = max(ret, solve(stp + 1, r1, r2 + 1));
		if(r1 + 1 < R && r2 + 1 < R) ret = max(ret, solve(stp + 1, r1 + 1, r2 + 1));
		if(ret != -1) {
			ret += grid[r1][c1];
			if(r1 != r2) ret += grid[r2][c2];
		}
	}
	return ret;
}

int main() {
	int i, j;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &R, &C);
		for(i = 0; i < R; i++)
			for(j = 0; j < C; j++)
				scanf("%d", &grid[i][j]);
		printf("Case %d: %d\n", cs, solve(0, 0, 0));
	}
	return 0;
}