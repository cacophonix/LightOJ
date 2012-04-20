#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;
typedef pair< int, pii > Edge;

int root[201];
vector< Edge > G[2];

int find(int u) {
	if(u != root[u]) root[u] = find(root[u]);
	return root[u];
}

int main() {
	int test, cs, i, u, v, w, n, e, q, pu, pv, from, to, cost;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		printf("Case %d:\n", cs);
		scanf("%d %d", &n, &q);
		G[(q-1)&1].clear();
		while(q--) {
			scanf("%d %d %d", &u, &v, &w);
			for(i = 1; i <= n; i++) root[i] = i;
			from = q&1, to = from^1; G[to].clear();
			for(i = e = cost = 0; e+1 < n && i < G[from].size(); i++) {
				if(G[from][i].first >= w) break;
				pu = find(G[from][i].second.first);
				pv = find(G[from][i].second.second);
				if(pu != pv) {
					cost += G[from][i].first;
					e++; G[to].push_back(G[from][i]);
					root[pu] = root[pv];
				}
			}
			pu = find(u); pv = find(v);
			if(pu != pv) {
				cost += w; e++; G[to].push_back(Edge(w, pii(u, v)));
				root[pu] = root[pv];
			}
			for(; e+1 < n && i < G[from].size(); i++) {
				pu = find(G[from][i].second.first);
				pv = find(G[from][i].second.second);
				if(pu != pv) {
					cost += G[from][i].first;
					e++; G[to].push_back(G[from][i]);
					root[pu] = root[pv];
				}
			}
			if(e == n-1) printf("%d\n", cost);
			else printf("-1\n");
		}
	}
	return 0;
}
