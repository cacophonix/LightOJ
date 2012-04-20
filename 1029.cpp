#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair< int, int > pii;
typedef pair< int, pii > edge;

vector< edge > G;
int root[101];

int find(int u) {
	if(u != root[u]) root[u] = find(root[u]);
	return root[u];
}

int main() {
	int test, cs, i, u, v, w, a, b, sz, e, n;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		G.clear(); sz = 0;
		while(scanf("%d %d %d", &u, &v, &w)==3 && w) {
			G.push_back(edge(w, pii(u, v)));
			sz++;
		}
		sort(G.begin(), G.end());
		a = b = 0; n++;
		for(i = 0; i < n; i++) root[i] = i;
		for(i = e = 0; e+1 < n && i < sz; i++) {
			u = find(G[i].second.first);
			v = find(G[i].second.second);
			if(u != v) {
				root[u] = root[v];
				e++; a += G[i].first;
			}
		}
		for(i = 0; i < n; i++) root[i] = i;
		for(i = sz-1, e = 0; e+1 < n && i >= 0; i--) {
			u = find(G[i].second.first);
			v = find(G[i].second.second);
			if(u != v) {
				root[u] = root[v];
				e++; b += G[i].first;
			}
		}
		if((a + b)&1) printf("Case %d: %d/2\n", cs, a+b);
		else printf("Case %d: %d\n", cs, (a+b)>>1);
	}
	return 0;
}
