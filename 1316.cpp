#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;
typedef pair< int, pii > pip;

const int MAX = 512;
const int INF = 0x3f3f3f3f;

vector< pii > G[MAX], RG[20];
int best, best_cost, shoploc[20], shopid[MAX], d[MAX], cost[17][1<<15], pops[1<<15];

void dijkstra(int s) {
	int u, v, w, e, i, sz;
	priority_queue< pii, vector< pii >, greater< pii > > Q;
	memset(d, 0x3f, sizeof d);
	Q.push(pii(0, s));
	d[s] = 0;
	while(!Q.empty()) {
		u = Q.top().second;
		w = Q.top().first;
		Q.pop();
		if(d[u] < w) continue;
		sz = G[u].size();
		for(i = 0; i < sz; i++) {
			v = G[u][i].first;
			e = G[u][i].second;
			if(d[v] > d[u] + e) {
				d[v] = d[u] + e;
				Q.push(pii(d[v], v));
			}
		}
	}
}

inline int popcount(int n) {
	int ret = 0;
	while(n > 0) {
		if(n & 1) ret++;
		n >>= 1;
	}
	return ret;
}

void dijkstra2(int s, int t, int ns) {
	int mask, u, w, sz, i, v, e, nmask, nb;
	priority_queue< pip, vector< pip >, greater< pip > > Q;
	memset(cost, 0x3f, sizeof cost);
	if(s >= ns) mask = 0; else mask = 1 << s;
	Q.push(pip(0, pii(s, mask)));
	cost[s][mask] = 0;
	while(!Q.empty()) {
		u = Q.top().second.first;
		mask = Q.top().second.second;
		w = Q.top().first;
		Q.pop();
		if(cost[u][mask] < w) continue;
		sz = RG[u].size();
		for(i = 0; i < sz; i++) {
			v = RG[u][i].first;
			e = RG[u][i].second;
			nmask = mask;
			if(v < ns) nmask |= (1 << v);
			if(cost[v][nmask] > e + cost[u][mask]) {
				cost[v][nmask] = e + cost[u][mask];
				Q.push(pip(cost[v][nmask], pii(v, nmask)));
			}
		}
	}
	best = 0, best_cost = INF;
	for(i = 0; i < (1 << ns); i++) {
		if(cost[t][i] < INF) {
			nb = pops[i];
			if(nb > best) {
				best = nb;
				best_cost = cost[t][i];
			}
			else if(nb == best) {
				best_cost = min(best_cost, cost[t][i]);
			}
		}
	}
}

int main() {
	int test, cs, n, rn, e, s, i, u, v, w;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(i = 0; i < (1 << 15); i++) pops[i] = popcount(i);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &n, &e, &s);
		memset(shopid, -1, sizeof(shopid));
		for(i = 0; i < s; i++) {
			scanf("%d", &u);
			shoploc[i] = u;
			shopid[u] = i;
		}
		if(shopid[0] == -1) {
			shopid[0] = i;
			shoploc[i++] = 0;
		}
		if(shopid[n-1] == -1) {
			shopid[n-1] = i;
			shoploc[i++] = n-1;
		}
		rn = i;
		for(i = 0; i < n; i++) G[i].clear();
		for(i = 0; i < e; i++) {
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(pii(v, w));
		}
		for(i = 0; i < rn; i++) {
			RG[i].clear();
			dijkstra(shoploc[i]);
			for(u = 0; u < n; u++) {
				if(u != shoploc[i] && shopid[u] != -1 && d[u] < INF) {
					RG[i].push_back(pii(shopid[u], d[u]));
				}
			}
		}
		dijkstra2(shopid[0], shopid[n-1], s);
		if(best_cost < INF) printf("Case %d: %d %d\n", cs, best, best_cost);
		else printf("Case %d: Impossible\n", cs);
	}
	return 0;
}
