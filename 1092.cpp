#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int R, C;
int dr[] = {-1, 0, 0, 1, -1, 1, -1, 1};
int dc[] = {0, -1, 1, 0, -1, -1, 1, 1};
bool grid[8][8], orig[8][8];

inline bool valid(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}

inline void toggle(int r, int c) {
	int i, r1, c1;
	grid[r][c] ^= true;
	for(i = 0; i < 8; i++) {
		r1 = r + dr[i], c1 = c + dc[i];
		if(valid(r1, c1)) grid[r1][c1] ^= true;
	}
}

int main() {
	int test, cs, i, j, best, moves, r, c, done;
	char buff[9];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &R, &C);
		for(i = 0; i < R; i++) {
			scanf("%s", buff);
			for(j = 0; j < C; j++) grid[i][j] = (buff[j] == '*');
		}
		best = INF;
		memcpy(orig, grid, sizeof grid);
		for(i = 0; i < (1 << C); i++) {
			for(j = 0; j < (1 << R); j++) {
				moves = 0;
				memcpy(grid, orig, sizeof orig);
				for(c = 0; c < C; c++) {
					if(i & (1 << c)) {
						toggle(0, c);
						moves++;
					}
				}
				for(r = 0; r < R; r++) {
					if(j & (1 << r)) {
						toggle(r, 0);
						moves++;
					}
				}
				for(r = 1; r < R; r++) {
					for(c = 1; c < C; c++) {
						if(!grid[r-1][c-1]) {
							toggle(r, c);
							moves++;
						}
					}
				}
				done = 0;
				for(r = 0; r < R && !done; r++)
					for(c = 0; c < C && !done; c++)
						if(!grid[r][c]) done = true;
				if(!done) best = min(best, moves);
			}
		}
		if(best == INF) printf("Case %d: impossible\n", cs);
		else printf("Case %d: %d\n", cs, best);
	}
	return 0;
}