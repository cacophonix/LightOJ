#include <cstdio>
#include <cstring>

int mat[101][101], g[101][101], deg[101];

void go(int u, int p, int &ret) {
	for(int i = 0; i < 2; i++) {
		if(g[u][i] != p) {
			ret += mat[u][g[u][i]];
			if(g[u][i] != 1) go(g[u][i], u, ret);
		}
	}
}

int main() {
	int test, cs, i, j, k, n, u, v, w, ret1, ret2;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		memset(deg, 0, sizeof deg);
		for(i = 0; i < n; i++) {
			scanf("%d %d %d", &u, &v, &w);
			mat[u][v] = 0; mat[v][u] = w;
			g[u][deg[u]++] = v; g[v][deg[v]++] = u;
		}
		ret1 = ret2 = 0;
		go(1, g[1][0], ret1);
		go(1, g[1][1], ret2);
		printf("Case %d: %d\n", cs, (ret1<ret2 ? ret1 : ret2));
	}
	return 0;
}
