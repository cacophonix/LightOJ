#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10000;
const int MAXE = 40000;

int from[MAXE], to[MAXE], next[MAXE], fin[MAXN], bridge[MAXE];
int low[MAXN], vis[MAXN], used[MAXN], dfsTime, nEdge, cnt, odd;

void addEdge(int u, int v) {
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
	for(int i = fin[u]; i >= 0; i = next[i]) {
		if(!bridge[i]) {
			if(!used[to[i]]) {
				used[to[i]] = 3 - used[from[i]];
				traverse(to[i]);
			}
			else if(used[to[i]] == used[from[i]]) odd = 1;
		}
	}
	cnt++;
}

int main() {
	int test, cs, n, m, i, u, v, res;
	//freopen("i.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &m);
		memset(fin, -1, sizeof(int)*n);
		memset(used, 0, sizeof(int)*n);
		for(i = nEdge = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			addEdge(u, v);
		}
		dfsTime = 0;
		for(i = 0; i < n; i++) if(!used[i]) findBridge(i, -1);
		memset(used, 0, sizeof(int)*n);
		for(i = res = 0; i < n; i++) {
			if(!used[i]) {
				odd = cnt = 0;
				used[i] = 1;
				traverse(i);
				if(odd) res += cnt;
			}
		}
		printf("Case %d: %d\n", cs, res);
	}
	return 0;
}