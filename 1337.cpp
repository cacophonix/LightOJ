#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

char grid[512][512];
int mat[512][512];
int R, C;
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

void bfs(int r, int c) {
	int i, cnt = 0, r1, c1;
	queue< int > Q;
	vector< int > V;
	Q.push(r); Q.push(c);
	mat[r][c] = 0;
	while(!Q.empty()) {
		r = Q.front(); Q.pop();
		c = Q.front(); Q.pop();
		if(grid[r][c] == 'C') cnt++;
		V.push_back(r); V.push_back(c);
		for(i = 0; i < 4; i++) {
			r1 = r + dr[i]; c1 = c + dc[i];
			if(0 <= r1 && r1 < R && 0 <= c1 && c1 < C) {
				if(grid[r1][c1] != '#' && mat[r1][c1] == -1) {
					mat[r1][c1] = 0;
					Q.push(r1); Q.push(c1);
				}
			}
		}
	}
	for(i = 0; i < V.size(); i+=2) mat[V[i]][V[i+1]] = cnt;
}

int main() {
	int test, cs, i, j, q;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &R, &C, &q);
		for(i = 0; i < R; i++) scanf("%s", grid[i]);
		memset(mat, -1, sizeof mat);
		for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				if(mat[i][j] == -1 && grid[i][j] != '#') bfs(i, j);
			}
		}
		printf("Case %d:\n", cs);
		while(q--) {
			scanf("%d %d", &i, &j);
			printf("%d\n", mat[i-1][j-1]);
		}
	}
	return 0;
}
