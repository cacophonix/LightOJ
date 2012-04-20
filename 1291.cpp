#include <cstdio>
#include <cstring>

#define min(a, b) (a < b ? a : b)

const int MAXN = 10000;
const int MAXE = 40000;

int from[MAXE], to[MAXE], next[MAXE], fin[MAXN], bridge[MAXE];
int low[MAXN], vis[MAXN], used[MAXN], dfsTime, nEdge;
int compo[MAXN], deg[MAXN], nComp;

inline void addEdge(int u, int v) {
	from[nEdge] = u, to[nEdge] = v, bridge[nEdge] = 0, next[nEdge] = fin[u], fin[u] = nEdge++;
	from[nEdge] = v, to[nEdge] = u, bridge[nEdge] = 0, next[nEdge] = fin[v], fin[v] = nEdge++;
}

void findBridge(int u, int par) {
	int i, v;
	used[u] = 1;
	vis[u] = low[u] = ++dfsTime;
	for(i = fin[u]; i >= 0; i = next[i]) {
		v = to[i];
		if(v == par) continue;
		if(used[v]) low[u] = min(low[u], vis[v]);
		else {
			findBridge(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > vis[u]) bridge[i] = bridge[i^1] = 1;
		}
	}
}

void traverse(int u) {
	used[u] = 1, compo[u] = nComp;
	for(int i = fin[u]; i >= 0; i = next[i]) {
		if(!bridge[i] && !used[to[i]]) {
			traverse(to[i]);
		}
	}
}

int main() {
	int test, cs, n, m, i, u, v;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &m);
		memset(fin, -1, sizeof(int)*n);
		memset(used, 0, sizeof(int)*n);
		for(i = nEdge = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			addEdge(u, v);
		}
		dfsTime = nComp = 0;
		findBridge(0, -1);
		memset(used, 0, sizeof(int)*n);
		for(i = 0; i < n; i++) {
			if(!used[i]) {
				traverse(i);
				nComp++;
			}
		}
		memset(deg, 0, sizeof(int)*nComp);
		for(i = 0; i < nEdge; i+=2) {
			if(bridge[i]) {
				deg[compo[from[i]]]++;
				deg[compo[to[i]]]++;
			}
		}
		for(i = m = 0; i < nComp; i++) m += (deg[i] == 1);
		printf("Case %d: %d\n", cs, (m + 1)>>1);
	}
	return 0;
}