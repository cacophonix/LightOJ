#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int test, cs, n, e, p, u, v, ex, in, i, j, k;
	int grid[100][100];
	scanf("%d", &cs);
	for(test = 1; test <= cs; test++) {
		scanf("%d %d %d", &n, &e, &p);
		memset(grid, 0x3f, sizeof grid);
		for(i = 0; i < n; i++) grid[i][i] = 0;
		for(i = 0; i < e; i++) {
			scanf("%d %d %d %d", &u, &v, &in, &ex);
			grid[u][v] = p*ex - in;
		}
		for(k = 0; k < n; k++)
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++)
					grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
		for(i = 0; i < n; i++) if(grid[i][i] < 0) break;
		if(i < n) printf("Case %d: YES\n", test);
		else printf("Case %d: NO\n", test);
	}
	return 0;
}
