#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define min(a, b) ((a)<(b)?(a):(b))

const int MAX = 10000;

vector< int > G[MAX];
int low[MAX], vis[MAX], used[MAX], cut[MAX], dfstime;

void dfs(int u, int par = -1) {
	int i, v, child = 0;
	used[u] = 1;
	vis[u] = low[u] = ++dfstime;
	for(i = 0; i < G[u].size(); i++) {
		v = G[u][i];
		if(v == par) continue;
		if(used[v]) low[u] = min(low[u], vis[v]);
		else {
			child++;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= vis[u]) cut[u] = 1;
		}
	}
	if(par == -1) cut[u] = child > 1;
}

int main() {
	int test, cs, n, e, i, u, v, cnt;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &e);
		for(i = 0; i < n; i++) {
			G[i].clear();
			used[i] = cut[i] = 0;
		}
		for(i = 0; i < e; i++) {
			scanf("%d %d", &u, &v);
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(0);
		for(cnt = u = 0; u < n; u++) cnt += cut[u];
		printf("Case %d: %d\n", cs, cnt);
	}
	return 0;
}
