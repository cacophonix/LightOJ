#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int mat[101][101], g[101][101], deg[101], d[101];

int bfs(int s, int t) {
	int i, u, v;
	queue< int > Q;
	Q.push(s); d[s] = 0;
	while(!Q.empty()) {
		u = Q.front(); Q.pop();
		for(i = 0; i < deg[u]; i++) {
			v = g[u][i];
			if(d[v] > d[u] + mat[u][v]) {
				d[v] = d[u] + mat[u][v];
				Q.push(v);
			}
		}
	}
	return d[t];
}

int main() {
	int test, cs, n, e, w, i, u, v;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &e);
		memset(mat, 0x3f, sizeof mat);
		memset(deg, 0, sizeof deg);
		memset(d, 0x3f, sizeof d);
		for(i = 0; i < e; i++) {
			scanf("%d %d %d", &u, &v, &w);
			if(mat[u][v] == 0x3f3f3f3f) {
				g[u][deg[u]++] = v;
				g[v][deg[v]++] = u;
			}
			mat[v][u] = mat[u][v] = min(mat[u][v], w);
		}
		w = bfs(1, n);
		if(w == 0x3f3f3f3f) printf("Case %d: Impossible\n", cs);
		else printf("Case %d: %d\n", cs, w);
	}
	return 0;
}
