#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef struct { int req, hav; } Node;

Node rtree[10001];
vector< int > G[10001];
bool flag[10001];
int moves;

int solve(int u) {
	int i, sz, sum, v, w;
	flag[u] = true;
	sz = G[u].size(), sum = rtree[u].hav - rtree[u].req;
	for(i = 0; i < sz; i++) {
		v = G[u][i];
		if(!flag[v]) {
			w = solve(v);
			sum += w;
			moves += abs(w);
		}
	}
	return sum;
}

int main() {
	int test, cs, n, e, u, v, w, i;
	freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 1; i <= n; i++) G[i].clear();
		for(i = 0; i < n; i++) {
			scanf("%d %d %d", &u, &w, &e);
			rtree[u].req = 1, rtree[u].hav = w;
			while(e--) {
				scanf("%d", &v);
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		memset(flag, 0, sizeof(flag));
		moves = 0;
		solve(1);
		printf("Case %d: %d\n", cs, moves);
	}
	return 0;
}
