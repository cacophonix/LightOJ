#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;

char vis[81][81][81], grid[82];
int d[81][81][81], cs, n;
int dt[4] = {0, 1, 0, -1}, can[3];

int tryToMove(int *u, int i, int t) {
	int x = u[i], ur = x / n, uc = x % n, p;
	int y = u[i] + dt[t], vr = y / n, vc = y % n;
	if(t & 1) { if(ur != vr || vc < 0 || vc >= n) return -1; }
	else { if(uc != vc || vr < 0 || vr >= n) return -1; }
	if(grid[y] == '#') return -1;
	if(isdigit(grid[y])) {
		p = grid[y] - '0';
		if(can[p] == -1) return -1;
		if(can[p] == 0) can[p] = tryToMove(u, p, t);
		if(can[p] == 1) return 1;
		else return -1;
	}
	return 1;
}

bool move(int *u, int *v, int t) {
	int i, j;
	memcpy(v, u, sizeof(int)*3);
	memset(can, 0, sizeof(int)*3);
	for(i = 0; i < 3; i++) {
		grid[u[i]] = i + '0';
	}
	for(i = 0; i < 3; i++) {
		if(can[i] == 0) {
			can[i] = tryToMove(u, i, t);
		}
	}
	for(i = j = 0; i < 3; i++) {
		grid[u[i]] = '.';
		if(can[i] == 1) {
			v[i] += dt[t];
			j++;
		}
	}
	return j != 0;
}

bool reached(int *u, int *v) {
	int i, val[81] = {0};
	for(i = 0; i < 3; i++) val[v[i]]++;
	for(i = 0; i < 3; i++) {
		if(val[u[i]] != 1) return false;
		else val[u[i]]++;
	}
	return true;
}

int bfs(int *start, int *finish) {
	queue< int > Q;
	int i, u[3], v[3];
	Q.push(start[0]), Q.push(start[1]), Q.push(start[2]);
	d[start[0]][start[1]][start[2]] = 0;
	vis[start[0]][start[1]][start[2]] = cs;
	while(!Q.empty()) {
		for(i = 0; i < 3; i++) u[i] = Q.front(), Q.pop();
		for(i = 0; i < 4; i++) {
			if(i == 2) {
				i = i;
			}
			if(move(u, v, i)) {
				if(vis[v[0]][v[1]][v[2]] != cs) {
					vis[v[0]][v[1]][v[2]] = cs;
					d[v[0]][v[1]][v[2]] = 1 + d[u[0]][u[1]][u[2]];
					if(reached(finish, v)) {
						return d[v[0]][v[1]][v[2]];
					}
					Q.push(v[0]), Q.push(v[1]), Q.push(v[2]);
				}
			}
		}
	}
	return -1;
}

int main() {
	int test, i, j, k, l, start[3], finish[3];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = k = l = 0; i < n; i++) {
			scanf("%s", &grid[i*n]);
			for(j = 0; j < n; j++) {
				if(grid[i*n + j] == 'X') finish[l++] = i*n+j, grid[i*n+j] = '.';
				else if(isalpha(grid[i*n + j])) start[k++] = i*n+j, grid[i*n+j] = '.';
			}
		}
		dt[0] = -n, dt[2] = n;
		k = bfs(start, finish);
		if(k == -1) printf("Case %d: trapped\n", cs);
		else printf("Case %d: %d\n", cs, k);
	}
	return 0;
}