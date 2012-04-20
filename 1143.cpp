#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <string>
using namespace std;

typedef pair< string, int > ps;

map< string, int > M;
map< string, int > :: iterator it;
char V[57427][26] = {"111110111100 110000100000"};
int D[57427];
char line[8], grid[26];
int dr[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
int dc[8] = {-1, +1, -2, +2, -2, +2, -1, +1};

void bfs() {
	int u, v, r1, r2, c1, c2, i, k = 1;
	char temp[26];
	queue< int > Q;
	Q.push(0); Q.push(2); Q.push(2);
	M.insert(ps(V[0], 0));
	while(!Q.empty()) {
		u = Q.front(); Q.pop();
		r1 = Q.front(); Q.pop();
		c1 = Q.front(); Q.pop();
		if(D[u] >= 10) continue;
		for(i = 0; i < 8; i++) {
			r2 = r1 + dr[i];
			c2 = c1 + dc[i];
			if(0 <= r2 && r2 < 5 && 0 <= c2 && c2 < 5) {
				strcpy(temp, V[u]);
				swap(temp[r1*5+c1], temp[r2*5+c2]);
				it = M.find(temp);
				if(it == M.end()) {
					M.insert(ps(temp, v = k++));
					strcpy(V[v], temp);
					D[v] = D[u] + 1;
					Q.push(v); Q.push(r2); Q.push(c2);
				}
			}
		}
	}
}

int main() {
	int test, cs, i, j, k;
	freopen("in.txt", "r", stdin);
	bfs();
	test = atoi(fgets(line, 8, stdin));
	for(cs = 1; cs <= test; cs++) {
		for(i = k = 0; i < 5; i++) {
			fgets(line, 8, stdin);
			for(j = 0; j < 5; j++) grid[k++] = line[j];
		}
		it = M.find(grid);
		if(it == M.end()) printf("Case %d: Unsolvable in less than 11 move(s).\n", cs);
		else printf("Case %d: Solvable in %d move(s).\n", cs, D[it->second]);
	}
	return 0;
}
