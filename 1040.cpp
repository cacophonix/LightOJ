#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;
typedef pair< int, pii > edge;

int root[55];
vector< edge > G;

int find(int u) {
	if(u != root[u]) root[u] = find(root[u]);
	return root[u];
}

int main() {
	int test, cs, n, i, j, w, total, sz, u, v, e;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		G.clear();
		for(i = 0; i < n; i++) root[i] = i;
		for(i = total = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				scanf("%d", &w);
				if(!w) continue;
				total += w;
				if(i != j) G.push_back(edge(w, pii(i, j)));
			}
		}
		sort(G.begin(), G.end()); sz = G.size();
		for(i = e = w = 0; e+1 < n && i < sz; i++) {
			u = find(G[i].second.first);
			v = find(G[i].second.second);
			if(u != v) {
				w += G[i].first; e++;
				root[u] = root[v];
			}
		}
		if(e != n-1) printf("Case %d: -1\n", cs);
		else printf("Case %d: %d\n", cs, total - w);
	}
	return 0;
}
