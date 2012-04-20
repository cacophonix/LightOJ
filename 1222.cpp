#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 110;
const int MAXE = 12100;
const int INF = 0x3f3f3f3f;

int src, snk, nNode, nEdge;
int fin[MAXN], pre[MAXN], dist[MAXN];
int cap[MAXE], cost[MAXE], next[MAXE], to[MAXE], from[MAXE];

inline void init(int _src, int _snk, int nodes) {
	memset(fin, -1, sizeof(fin));
	nNode = nodes, nEdge = 0;
	src = _src, snk = _snk;
}

inline void addEdge(int u, int v, int _cap, int _cost) {
	from[nEdge] = u, to[nEdge] = v, cap[nEdge] = _cap, cost[nEdge] = _cost;
	next[nEdge] = fin[u], fin[u] = nEdge++;
	from[nEdge] = v, to[nEdge] = u, cap[nEdge] = 0, cost[nEdge] = -(_cost);
	next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bellman() {
	int iter, u, v, i;
	bool flag = true;
	memset(dist, 0x3f, sizeof(dist));
	memset(pre, -1, sizeof(pre));
	dist[src] = 0;
	for(iter = 1; iter < nNode && flag; iter++) {
		flag = false;
		for(u = 0; u < nNode; u++) {
			for(i = fin[u]; i >= 0; i = next[i]) {
				v = to[i];
				if(cap[i] && dist[v] > dist[u] + cost[i]) {
					dist[v] = dist[u] + cost[i];
					pre[v] = i;
					flag = true;
				}
			}
		}
	}
	return (dist[snk] < INF);
}

int mcmf(int &fcost) {
	int netflow, bot, u;
	netflow = fcost = 0;
	while(bellman()) {
		bot = INF;
		for(u = pre[snk]; u >= 0; u = pre[from[u]]) bot = std::min(bot, cap[u]);
		for(u = pre[snk]; u >= 0; u = pre[from[u]]) {
			cap[u] -= bot;
			cap[u^1] += bot;
			fcost += bot * cost[u];
		}
		netflow += bot;
	}
	return netflow;
}

int main() {
	int test, cs, fcost, mflow, n, i, j, v;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		init(0, (n<<1)+1, (n<<1)+2);
		for(i = 1; i <= n; i++) {
			addEdge(src, i, 1, 0);
			addEdge(n+i, snk, 1, 0);
		}
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				scanf("%d", &v);
				addEdge(i, n+j, 1, -v);
			}
		}
		mflow = mcmf(fcost);
		printf("Case %d: %d\n", cs, -fcost);
	}
	return 0;
}
