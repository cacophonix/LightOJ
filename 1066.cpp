#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;

int pos[26][2];
char grid[10][11];
int d[10][10], n;
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

inline bool valid(int r, int c) {
	return 0 <= r && r < n && 0 <= c && c < n;
}

int bfs(int s, int t) {
	int ur = pos[s][0], uc = pos[s][1], vr, vc, i;
	queue< int > Q;
	d[ur][uc] = 0;
	Q.push(ur); Q.push(uc);
	while(!Q.empty()) {
		ur = Q.front(); Q.pop();
		uc = Q.front(); Q.pop();
		for(i = 0; i < 4; i++) {
			vr = ur + dr[i];
			vc = uc + dc[i];
			if(valid(vr, vc) && grid[vr][vc] != '#' && d[vr][vc] == -1) {
				d[vr][vc] = d[ur][uc] + 1;
				if(vr == pos[t][0] && vc == pos[t][1]) return d[vr][vc];
				Q.push(vr); Q.push(vc);
			}
		}
	}
	return -1;
}

int main() {
	int test, cs, i, j, k, ans;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = k = 0; i < n; i++) {
			scanf("%s", grid[i]);
			for(j = 0; j < n; j++) {
				if(isalpha(grid[i][j])) {
					pos[grid[i][j] - 'A'][0] = i, pos[grid[i][j] - 'A'][1] = j;
					grid[i][j] = '#'; k++;
				}
			}
		}
		for(i = 1, ans = 0; i < k; i++) {
			grid[pos[i-1][0]][pos[i-1][1]] = '.';
			grid[pos[i][0]][pos[i][1]] = '.';
			memset(d, -1, sizeof d);
			j = bfs(i-1, i);
			if(j == -1) break;
			ans += j;
		}
		if(i < k) printf("Case %d: Impossible\n", cs);
		else printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}