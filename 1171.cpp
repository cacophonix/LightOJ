#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define NIL 0
#define INF 0x3f3f3f3f
#define MAX 20001

int grid[200][200], R, C, lt, rt, n;
int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

vector< int > G[MAX];
int Left[MAX], Right[MAX], dist[MAX];

inline bool valid(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}

void traverse(int r, int c, int d) {
	int i, r1, c1;
	if(d & 1) grid[r][c] = ++rt;
	else {
		grid[r][c] = ++lt;
		G[lt].clear();
	}
	for(i = 0; i < 8; i++) {
		r1 = r + dr[i];
		c1 = c + dc[i];
		if(valid(r1, c1) && grid[r1][c1]) {
			if(grid[r1][c1] == -1) traverse(r1, c1, d + 1);
			if(!(d & 1)) {
				G[grid[r][c]].push_back(grid[r1][c1]);
			}
		}
	}
}

void createGraph() {
	int i, j;
	lt = rt = 0;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(grid[i][j] == -1) {
				traverse(i, j, 0);
			}
		}
	}
}

bool bfs() {
	int i, u, v, len;
	queue< int > Q;
	for(i=1; i<=n; i++) {
		if(Left[i]==NIL) {
			dist[i] = 0;
			Q.push(i);
		}
		else dist[i] = INF;
	}
	dist[NIL] = INF;
	while(!Q.empty()) {
		u = Q.front(); Q.pop();
		if(u!=NIL) {
			len = G[u].size();
			for(i=0; i<len; i++) {
				v = G[u][i];
				if(dist[Right[v]]==INF) {
					dist[Right[v]] = dist[u] + 1;
					Q.push(Right[v]);
				}
			}
		}
	}
	return (dist[NIL]!=INF);
}

bool dfs(int u) {
	int i, v, len;
	if(u!=NIL) {
		len = G[u].size();
		for(i=0; i<len; i++) {
			v = G[u][i];
			if(dist[Right[v]]==dist[u]+1) {
				if(dfs(Right[v])) {
					Right[v] = u;
					Left[u] = v;
					return true;
				}
			}
		}
		dist[u] = INF;
		return false;
	}
	return true;
}

int hopcroft_karp() {
	int matching = 0, i;
	CLR(Left);
	CLR(Right);
	n = lt;
	while(bfs())
		for(i=1; i<=n; i++)
			if(Left[i]==NIL && dfs(i))
				matching++;
	return matching;
}

int main() {
	int test, cs, r, c, b, i;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &R, &C, &b);
		SET(grid);
		for(i = 0; i < b; i++) {
			scanf("%d %d", &r, &c);
			r--, c--;
			grid[r][c] = 0;
		}
		createGraph();
		printf("Case %d: %d\n", cs, lt + rt - hopcroft_karp());
	}
	return 0;
}