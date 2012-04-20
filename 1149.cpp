#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 128;

vector < int > G[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX];

bool dfs(int u) {
	if(visited[u]) return false;
	visited[u] = true;
	int len = G[u].size(), i, v;
	for(i=0; i<len; i++) {
		v = G[u][i];
		if(Right[v]==-1) {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	for(i=0; i<len; i++) {
		v = G[u][i];
		if(dfs(Right[v])) {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	return false;
}

int match(int n) {
	int i, ret = 0;
	bool done;
	memset(Left, -1, sizeof Left);
	memset(Right, -1, sizeof Right);
	do {
		done = true;
		memset(visited, 0, sizeof visited);
		for(i=0; i<n; i++) {
			if(Left[i]==-1 && dfs(i)) {
				done = false;
			}
		}
	} while(!done);
	for(i=0; i<n; i++) ret += (Left[i]!=-1);
	return ret;
}

int main() {
	int test, cs, n, m, i, j;
	int a[MAX], b[MAX];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d", a + i);
		scanf("%d", &m);
		for(j = 0; j < m; j++) scanf("%d", b + j);
		for(i = 0; i < n; i++) {
			G[i].clear();
			for(j = 0; j < m; j++) if(!b[j] || (a[i] && b[j] % a[i] == 0)) G[i].push_back(j);
		}
		printf("Case %d: %d\n", cs, match(n));
	}
	return 0;
}