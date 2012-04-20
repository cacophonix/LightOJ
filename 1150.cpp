#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;
typedef pair< pii, int > edge;

const int MAX = 128;
const int INF = 0x7f7f7f7f;

char grid[25][26];
int n, hk, gk, lo, hi, num[25][25], d[25][25];
int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};
vector< edge > E;
vector< int > G[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX];
 
bool dfs(int u) {
	if(visited[u]) return false;
	visited[u] = true;
	int len = G[u].size(), i, v;
	for(i=0; i<len; i++) {
		v = G[u][i];
		if(Right[v]==-1) {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	for(i=0; i<len; i++) {
		v = G[u][i];
		if(dfs(Right[v])) {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	return false;
}
 
int match(int n) {
	int i, ret = 0;
	bool done;
	memset(Left, -1, sizeof Left);
	memset(Right, -1, sizeof Right);
	do {
		done = true;
		memset(visited, 0, sizeof visited);
		for(i=1; i<=n; i++) {
			if(Left[i]==-1 && dfs(i)) {
				done = false;
			}
		}
	} while(!done);
	for(i=1; i<=n; i++) ret += (Left[i]!=-1);
	return ret;
}

inline bool valid(int r, int c) {
	return 0 <= r && r < n && 0 <= c && c < n;
}

void bfs(int r, int c, int gid) {
	int i, r1, c1;
	queue< int > Q;
	Q.push(r), Q.push(c);
	memset(d, -1, sizeof d);
	d[r][c] = 0;
	while(!Q.empty()) {
		r = Q.front(); Q.pop();
		c = Q.front(); Q.pop();
		for(i = 0; i < 4; i++) {
			r1 = r + dr[i];
			c1 = c + dc[i];
			if(valid(r1, c1) && grid[r1][c1] != '#' && d[r1][c1] == -1) {
				d[r1][c1] = d[r][c] + 1;
				if(grid[r1][c1] == 'H') {
					E.push_back(edge(pii(gid, num[r1][c1]), (1+d[r1][c1])<<1));
					lo = min(lo, (1+d[r1][c1])<<1);
					hi = max(hi, (1+d[r1][c1])<<1);
				}
				Q.push(r1), Q.push(c1);
			}
		}
	}
}

int main() {
	int test, cs, i, j;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		hk = gk = 0;
		lo = INF, hi = -INF;
		for(i = 0; i < n; i++) {
			scanf("%s", grid[i]);
			for(j = 0; j < n; j++) {
				if(grid[i][j] == 'H') num[i][j] = ++hk;
				else if(grid[i][j] == 'G') num[i][j] = ++gk;
			}
		}
		E.clear();
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if(grid[i][j] == 'G') {
					bfs(i, j, num[i][j]);
				}
			}
		}
		for(i = 1; i <= gk; i++) G[i].clear();
		for(i = 0; i < E.size(); i++)
			if(E[i].second <= hi)
				G[E[i].first.first].push_back(E[i].first.second);
		if(match(gk) < hk) {
			printf("Case %d: Vuter Dol Kupokat\n", cs);
			continue;
		}
		while(lo < hi) {
			j = (lo + hi) >> 1;
			for(i = 1; i <= gk; i++) G[i].clear();
			for(i = 0; i < E.size(); i++)
				if(E[i].second <= j)
					G[E[i].first.first].push_back(E[i].first.second);
			if(match(gk) == hk) hi = j;
			else lo = j + 1;
		}
		printf("Case %d: %d\n", cs, hi);
	}
	return 0;
}