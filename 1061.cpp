#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int flag[8][8], board[8][8], inp[8][2], target[92][8], dp[8][1<<8], k;

void placement(int r, int c, int d) {
	int i, j;
	board[r][c] += d;
	for(i=0;i<8;i++) {
		flag[r][i] += d;
		flag[i][c] += d;
	}
	for(i=r+1,j=c+1;i<8 && j<8;i++,j++) flag[i][j] += d;
	for(i=r-1,j=c-1;i>=0 && j>=0;i--,j--) flag[i][j] += d;
	for(i=r+1,j=c-1;i<8 && j>=0;i++,j--) flag[i][j] += d;
	for(i=r-1,j=c+1;i>=0 && j<8;i--,j++) flag[i][j] += d;
}

void save_sol() {
	int i, j;
	for(i=0;i<8;i++) {
		for(j=0;j<8;j++) {
			if(board[i][j]==1) {
				target[k][i] = j;
				break;
			}
		}
	}
	k++;
}

void search(int col) {
	if(col==8) {
		save_sol();
		return;
	}
	for(int i=0;i<8;i++) {
		if(flag[i][col]==0) {
			placement(i,col,+1);
			search(col+1);
			placement(i,col,-1);
		}
	}
}

int cost(int conf, int from, int to) {
	int r1, r2, c1, c2;
	r1 = inp[from][0]; c1 = inp[from][1];
	r2 = to; c2 = target[conf][to];
	if(r1 == r2 && c1 == c2) return 0;
	if(r1 == r2 || c1 == c2) return 1;
	if(abs(r1-r2) == abs(c1-c2)) return 1;
	return 2;
}

int solve(int u, int mask, int conf) {
	if(u == 8) return 0;
	if(dp[u][mask] != -1) return dp[u][mask];
	int &ret = dp[u][mask]; ret = INF;
	for(int i = 0; i < 8; i++) {
		if(mask & (1 << i)) continue;
		ret = min(ret, cost(conf, u, i) + solve(u + 1, mask | (1 << i), conf));
	}
	return ret;
}

int main() {
	int i, j, test, cs, best;
	char grid[8][10];
	search(0);
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		for(i = k = 0; i < 8; i++) {
			scanf("%s", grid[i]);
			for(j = 0; j < 8; j++) {
				if(grid[i][j] == 'q') {
					inp[k][0] = i;
					inp[k][1] = j;
					k++;
				}
			}
		}
		for(i = 0, best = INF; i < 92; i++) {
			memset(dp, -1, sizeof dp);
			best = min(best, j = solve(0, 0, i));
		}
		printf("Case %d: %d\n", cs, best);
	}
	return 0;
}
