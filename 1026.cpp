#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 10001;

vector< int > G[MAX];
vector< pair< int, int > > Bridges;
int fup[MAX], tin[MAX], used[MAX], dfstime;

void dfs(int u, int par) {
	int i, v, m, n, sz = G[u].size();
	used[u] = 1;
	tin[u] = fup[u] = ++dfstime;
	for(i = 0; i < sz; i++) {
		v = G[u][i];
		if(v == par) continue;
		if(used[v]) fup[u] = min(fup[u], tin[v]);
		else {
			dfs(v, u);
			fup[u] = min(fup[u], fup[v]);
			if(fup[v] > tin[u]) {
				m = u, n = v;
				if(m > n) swap(m, n);
				Bridges.push_back(make_pair(m, n));
			}
		}
	}
}

int main() {
	int n, k, u, v, test, cs = 1, i, sz;
	char num[20];
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		dfstime = 0;
		Bridges.clear();
		for(i = 0; i < n; i++) {
			G[i].clear();
			used[i] = 0;
		}
		for(i = 0; i < n; i++) {
			scanf("%d%s", &u, num);
			k = atoi(&num[1]);
			while(k--) {
				scanf("%d", &v);
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		for(i = 0; i < n; i++) if(!used[i]) dfs(i, -1);
		sort(Bridges.begin(), Bridges.end());
		printf("Case %d:\n%d critical links\n", cs++, sz = Bridges.size());
		for(i = 0; i < sz; i++) printf("%d - %d\n", Bridges[i].first, Bridges[i].second);
	}
	return 0;
}
