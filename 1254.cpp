#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100;
const int INF = 0x7f7f7f7f;

typedef pair< int, int > pii;
typedef pair< pii, int > ppi;

vector< pii > G[MAX];
int d[MAX][101], cost[MAX];

int dijkstra(int st, int en, int cap) {
	int u, v, w, e, t, r, p, i, sz, ret = INF;
	priority_queue< ppi, vector< ppi >, greater< ppi > > Q;
	memset(d, 0x7f, sizeof d);
	d[st][0] = 0;
	Q.push(ppi(pii(d[st][0], 0), st));
	while(!Q.empty()) {
		u = Q.top().second;
		w = Q.top().first.first;
		t = Q.top().first.second;
		Q.pop();
		if(d[u][t] < w) continue;
		if(u == en) return d[u][t];
		sz = G[u].size();
		for(i = 0; i < sz; i++) {
			v = G[u][i].second;
			e = G[u][i].first;
			if(e > cap) continue;
			if(t >= e && d[v][t-e] > d[u][t]) {
				d[v][t-e] = d[u][t];
				Q.push(ppi(pii(d[v][t-e], t-e), v));
			}
		}
		if(t < cap) {
			d[u][t+1] = d[u][t] + cost[u];
			Q.push(ppi(pii(d[u][t+1], t+1), u));
		}
	}
	return ret;
}

int main() {
	int n, e, i, u, v, w, q, test, cs;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &e);
		for(i = 0; i < n; i++) {
			scanf("%d", cost + i);
			G[i].clear();
		}
		for(i = 0; i < e; i++) {
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(pii(w, v));
			G[v].push_back(pii(w, u));
		}
		printf("Case %d:\n", cs);
		scanf("%d", &q);
		while(q--) {
			scanf("%d %d %d", &w, &u, &v);
			i = dijkstra(u, v, w);
			if(i == INF) printf("impossible\n");
			else printf("%d\n", i);
		}
	}
	return 0;
}
