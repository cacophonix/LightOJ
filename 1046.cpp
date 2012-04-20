#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 0x7f7f7f7f;

char grid[10][11];
int d[10][10], df[10][10];
int dr[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dc[] = {2, -2, 1, -1, 2, -2, 1, -1};
int R, C;

bool valid(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}

void bfs(int r, int c, int k) {
	int ur, uc, vr, vc, i, j;
	queue< int > Q;
	memset(d, -1, sizeof d);
	Q.push(r), Q.push(c);
	d[r][c] = 0;
	while(!Q.empty()) {
		ur = Q.front(); Q.pop();
		uc = Q.front(); Q.pop();
		//for(it = S[k].begin(); it != S[k].end(); it++) {
		for(i = 0; i < 8; i++) {
			//vr = ur + it->first;
			//vc = uc + it->second;
			vr = ur + dr[i];
			vc = uc + dc[i];
			if(valid(vr, vc) && d[vr][vc] == -1) {
				d[vr][vc] = d[ur][uc] + 1;
				Q.push(vr), Q.push(vc);
			}
		}
	}
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(d[i][j] == -1 || df[i][j] == -1) df[i][j] = -1;
			else df[i][j] += (d[i][j] + k - 1) / k;
		}
	}
}

int main() {
	int test, cs, i, j, res, done;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &R, &C);
		for(i = 0; i < R; i++) scanf("%s", grid[i]);
		memset(df, 0, sizeof df);
		for(i = done = 0; !done && i < R; i++) {
			for(j = 0; !done && j < C; j++) {
				if(grid[i][j] != '.') {
					if(df[i][j] != -1) bfs(i, j, grid[i][j] - '0');
					else done = 1;
				}
			}
		}
		for(i = 0, res = INF; !done && i < R; i++) {
			for(j = 0; j < C; j++) {
				if(df[i][j] != -1) if(res > df[i][j]) res = df[i][j];
			}
		}
		if(done || res == INF) printf("Case %d: -1\n", cs);
		else printf("Case %d: %d\n", cs, res);
	}
	return 0;
}