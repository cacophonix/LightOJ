#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char grid[20][21];
int cell[20][20];
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};
vector< int > G[200];
bool visited[200];
int Left[200], Right[200];
 
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
		for(i=0; i<n; i++) {
			if(Left[i]==-1 && dfs(i)) {
				done = false;
			}
		}
	} while(!done);
	for(i=0; i<n; i++) ret += (Left[i]!=-1);
	return ret;
}

int main() {
	int r, c, test, cs, i, j, k, kr, kl, r1, c1;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &r, &c);
		for(i = kr = kl = 0; i < r; i++) {
			scanf("%s", grid[i]);
			for(j = 0; j < c; j++) if(grid[i][j] == '*') {
				if((i+j)&1) cell[i][j] = kr++;
				else cell[i][j] = kl++;
			}
		}
		for(i = 0; i < kl; i++) G[i].clear();
		for(i = 0; i < r; i++) {
			for(j = 0; j < c; j++) {
				if(!((i+j) & 1) && grid[i][j] == '*') {
					for(k = 0; k < 4; k++) {
						r1 = i + dr[k];
						c1 = j + dc[k];
						if(0 <= r1 && r1 < r && 0 <= c1 && c1 < c && grid[r1][c1] == '*') {
							G[cell[i][j]].push_back(cell[r1][c1]);
						}
					}
				}
			}
		}
		printf("Case %d: %d\n", cs, kr + kl - match(kl));
	}
	return 0;
}