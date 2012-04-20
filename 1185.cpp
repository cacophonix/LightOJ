#include <cstdio>
#include <cstring>

const int MAX = 128;

int G[MAX][MAX], deg[MAX], Q[MAX << 2], d[MAX][2];

void bfs(int s) {
	int u, v, sz, i, m, n, st, en;
	st = en = 0;
	memset(d, 0, sizeof d);
	Q[en++] = s, Q[en++] = 0;
	while(st < en) {
		u = Q[st++];
		m = Q[st++];
		for(i = 0; i < deg[u]; i++) {
			v = G[u][i];
			n = m ^ 1;
			if(!d[v][n]) {
				d[v][n] = 1;
				Q[en++] = v, Q[en++] = n;
			}
		}
	}
}

int main() {
	int test, cs, n, e, u, v, i;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &e);
		memset(deg, 0, sizeof deg);
		for(i = 0; i < e; i++) {
			scanf("%d %d", &u, &v);
			G[u][deg[u]++] = v;
			G[v][deg[v]++] = u;
		}
		bfs(1);
		for(i = 1, e = 0; i <= n; i++) if(d[i][0]) e++;
		printf("Case %d: %d\n", cs, e);
	}
	return 0;
}
