#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 10001;

int test, cs, flv;
vector< int > G[MAX];
int flag[MAX], stck[MAX], top;

void dfs1(int u) {
	int i, v, sz = G[u].size();
	for(i = 0; i < sz; i++) {
		v = G[u][i];
		if(flag[v]!=flv) {
			flag[v] = flv;
			dfs1(v);
		}
	}
	stck[top++] = u;
}

void dfs2(int u) {
	int i, v, sz = G[u].size();
	for(i = 0; i < sz; i++) {
		v = G[u][i];
		if(flag[v] != flv) {
			flag[v] = flv;
			dfs2(v);
		}
	}
}

int main() {
	int n, e, i, u, v;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &e);
		for(i = 1; i <= n; i++) G[i].clear();
		while(e--) {
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
		}
		for(u = 1, flv = cs << 1, top = 0; u <= n; u++) {
			if(flag[u] != flv) {
				flag[u] = flv;
				dfs1(u);
			}
		}
		for(flv++, i = 0; top--; ) {
			u = stck[top];
			if(flag[u] != flv) {
				flag[u] = flv; i++;
				dfs2(u);
			}
		}
		printf("Case %d: %d\n", cs, i);
	}
	return 0;
}
