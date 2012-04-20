#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;

char grid[20][20];
int dp[16][1<<16], n;
pii g[16];

inline int dist(const pii &a, const pii &b) {
	return max(abs(a.first - b.first), abs(a.second - b.second));
}

int solve(int u, int mask) {
	if(mask == (1 << n) - 1) return dist(g[u], g[0]);
	if(dp[u][mask] != -1) return dp[u][mask];
	int &ret = dp[u][mask]; ret = 0x3f3f3f3f;
	for(int i = 0; i < n; i++)
		if((mask & (1 << i)) == 0)
			ret = min(ret, dist(g[u], g[i]) + solve(i, mask | (1 << i)));
	return ret;
}

int main() {
	int test, cs, i, j, r, c;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &r, &c);
		for(n = 1, i = 0; i < r; i++) {
			scanf("%s", grid[i]);
			for(j = 0; j < c; j++) {
				if(grid[i][j] == 'x') g[0] = pii(i, j);
				else if(grid[i][j] == 'g') g[n++] = pii(i, j);
			}
		}
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", cs, solve(0, 1));
	}
	return 0;
}