#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

#define MAX 5005
#define INF 0x3f3f3f3f
#define pii pair< int, int >
#define ppi pair< pii, int >
#define ff first
#define ss second

vector< pii > G[MAX];
int d[MAX][2];
set< int > S;
set< int >::iterator it;

int dijkstra(int src, int dst) {
	int i, u, v, w, best, sbest, sz, nbest, nsbest;
	priority_queue< ppi, vector< ppi >, greater< ppi > > Q;
	d[src][0] = 0;
	Q.push(ppi(pii(0, INF), src));
	while(!Q.empty()) {
		best = Q.top().ff.ff;
		sbest = Q.top().ff.ss;
		u = Q.top().ss; Q.pop();
		sz = G[u].size();
		for(i = 0; i < sz; i++) {
			v = G[u][i].ss;
			w = G[u][i].ff;
			S.clear();
			S.insert(min(best+w, INF));
			S.insert(min(sbest+w, INF));
			S.insert(d[v][0]);
			S.insert(d[v][1]);
			it = S.begin();
			nbest = *it++; nsbest = *it;
			if(d[v][0] > nbest || d[v][1] > nsbest) {
				d[v][0] = nbest, d[v][1] = nsbest;
				Q.push(ppi(pii(d[v][0], d[v][1]), v));
			}
		}
	}
	return d[dst][1];
}

int main() {
	int n, u, v, w, e, i, ret, test, cs = 1;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d", &n, &e);
		for(i = 1; i <= n; i++) G[i].clear();
		memset(d, 0x3f, sizeof d);
		for(i = 0; i < e; i++) {
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(pii(w, v));
			G[v].push_back(pii(w, u));
		}
		ret = dijkstra(1, n);
		if(ret == INF) printf("Case %d: -1\n", cs++);
		else printf("Case %d: %d\n", cs++, ret);
	}
	return 0;
}

