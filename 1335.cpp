#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int G[512][2], ord[512];
char vis[512];

void dfs(int u, int d) {
	ord[u] = d; vis[u] = 1;
	for(int i = 0; i < 2; i++) {
		if(!vis[G[u][i]]) dfs(G[u][i], d + 1);
	}
}

int lis(int n) {
	vector< int > V;
	V.push_back(ord[1]);
	for(int i = 2; i <= n; i++) {
		if(ord[i] > V.back()) V.push_back(ord[i]);
		else *lower_bound(V.begin(), V.end(), ord[i]) = ord[i];
	}
	return V.size();
}

int main() {
	int test, cs, n, i, res;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 1; i <= n; i++) scanf("%d %d", &G[i][0], &G[i][1]);
		for(res = n, i = 1; i <= n; i++) {
			memset(vis, 0, sizeof vis);
			dfs(i, 0);
			res = min(res, n - lis(n));
			swap(G[i][0], G[i][1]);
			memset(vis, 0, sizeof vis);
			dfs(i, 0);
			res = min(res, n - lis(n));
		}
		printf("Case %d: %d\n", cs, res);
	}
	return 0;
}
