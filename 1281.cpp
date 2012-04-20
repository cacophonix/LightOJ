#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair< int, int > pii;
typedef pair< pii, int > ppi;

const int MAX = 10001;
const int INF = 0x3f3f3f3f;

vector< ppi > G[MAX];
int d[MAX][11];

int dijkstra(int st, int en, int lim) {
	int u, v, w, e, x, y, sz, i, ret = INF;
	priority_queue< ppi, vector< ppi >, greater< ppi > > Q;
	memset(d, 0x3f, sizeof d);
	d[st][0] = 0;
	Q.push(ppi(pii(d[st][0], 0), st));
	while(!Q.empty()) {
		u = Q.top().second;
		w = Q.top().first.first;
		x = Q.top().first.second;
		Q.pop();
		if(d[u][x] < w) continue;
		sz = G[u].size();
		for(i = 0; i < sz; i++) {
			v = G[u][i].second;
			e = G[u][i].first.first;
			y = G[u][i].first.second;
			if(x + y > lim) continue;
			if(d[v][x+y] > d[u][x] + e) {
				d[v][x+y] = d[u][x] + e;
				Q.push(ppi(pii(d[v][x+y], x+y), v));
			}
		}
	}
	for(i = 0; i <= lim; i++) ret = min(ret, d[en][i]);
	return ret;
}

int main() {
	int test, cs, i, u, v, w, ret, n, e, prop, lim;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d %d", &n, &e, &prop, &lim);
		for(i = 0; i < n; i++) G[i].clear();
		for(i = 0; i < e; i++) {
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(ppi(pii(w, 0), v));
		}
		for(i = 0; i < prop; i++) {
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(ppi(pii(w, 1), v));
		}
		ret = dijkstra(0, n-1, lim);
		if(ret == INF) printf("Case %d: Impossible\n", cs);
		else printf("Case %d: %d\n", cs, ret);
	}
	return 0;
}
