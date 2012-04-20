#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;
typedef unsigned long long i64;

const int MAX = 10000;

vector< int > G[MAX];
int dfstime, cnt, cuts, ncoms, low[MAX], vis[MAX], used[MAX], cut[MAX];

void findcut(int u, int par) {
	int i, v, child = 0;
	used[u] = 1;
	vis[u] = low[u] = ++dfstime;
	for(i = 0; i < G[u].size(); i++) {
		v = G[u][i];
		if(v == par) continue;
		if(used[v]) low[u] = min(low[u], vis[v]);
		else {
			child++;
			findcut(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= vis[u]) cut[u] = 1;
		}
	}
	if(par == -1) cut[u] = (child > 1);
}

void dfs(int u) {
	int i, v, sz = G[u].size();
	used[u] = 1; cnt++;
	for(i = 0; i < sz; i++) {
		v = G[u][i];
		if(!used[v] && !cut[v]) dfs(v);
		if(cut[v] && used[v] != ncoms + 1) {
			cuts++;
			used[v] = ncoms + 1;
		}
	}
}

int main() {
	int n, e, i, u, v, test, cs, ans;
	i64 nways;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &e);
		for(i = 0; i < n; i++) G[i].clear();
		for(i = 0; i < e; i++) {
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		memset(used, 0, sizeof used);
		memset(cut, 0, sizeof cut);
		dfstime = ncoms = ans = 0, nways = 1;
		findcut(0, -1);
		memset(used, 0, sizeof used);
		for(i = 0; i < n; i++) {
			if(!used[i] && !cut[i]) {
				cnt = cuts = 0;
				dfs(i);
				ncoms++;
				if(cuts < 2) {
					ans++;
					nways = nways * cnt;
				}
			}
		}
		if(ans == 1) {
			nways = (n * (n - 1)) >> 1;
			ans++;
		}
		printf("Case %d: %d %llu\n", cs, ans, nways);
	}
	return 0;
}