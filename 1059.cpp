#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long i64;
typedef pair< int, int > pii;
typedef pair< int, pii > edge;
const int MAXN = 10001, MAXE = 100001;

int parent[MAXN];
edge G[MAXE], MST[MAXE];
bool flag[MAXN];

int find(int u) {
	if(u!=parent[u]) parent[u] = find(parent[u]);
	return parent[u];
}

int main() {
	int t, cs = 1, i;
	int N, E, mstE, u, v, w, cnt;
	i64 total, acost;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%lld", &N, &E, &acost);
		for(i = 1; i <= N; i++) {
			parent[i] = i;
			flag[i] = 0;
		}
		for(i = 0; i < E; i++) {
			scanf("%d%d%d", &u, &v, &w);
			G[i] = edge(w, pii(u, v));
		}
		sort(G, G+E);
		total = mstE = cnt = 0;
		for(i = 0; i < E; i++) {
			u = find(G[i].second.first);
			v = find(G[i].second.second);
			w = G[i].first;
			if(u != v) {
				MST[mstE++] = G[i];
				total += (i64)w;
				parent[u] = parent[v];
			}
		}
		for(i = 1; i <= N; i++) {
			u = find(i);
			if(!flag[u]) {
				flag[u] = 1;
				cnt++;
			}
		}
		total += acost * cnt;
		for(i = mstE-1; i>=0; i--) {
			if(MST[i].first >= acost) {
				cnt++;
				total -= (i64)MST[i].first;
				total += acost;
			}
			else break;
		}
		printf("Case %d: %lld %d\n", cs++, total, cnt);
	}
	return 0;
}
