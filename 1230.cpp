#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 1001;

vector< int > G[MAX];
int color[MAX][2], dual[MAX][2];

void solve(int u, int c, int p) {
	if(color[u][c] != -1) return;
	int i, v, sz, color1, dual1, color0, dual0, colorM, dualM, cm, dm;
	sz = G[u].size(); cm = dm = 0;
	for(i = 0; i < sz; i++) {
		v = G[u][i];
		if(v == p) continue;
		if(c == 1) {
			solve(v, 1, u);
			color1 = color[v][1], dual1 = dual[v][1] + 1;
			solve(v, 0, u);
			color0 = color[v][0], dual0 = dual[v][0];

			if(color1 > color0) colorM = color0, dualM = dual0;
			else if(color1 < color0) colorM = color1, dualM = dual1;
			else if(dual1 > dual0) colorM = color1, dualM = dual1;
			else colorM = color0, dualM = dual0;
		}
		else {
			solve(v, 1, u);
			colorM = color[v][1], dualM = dual[v][1];
		}
		cm += colorM; dm += dualM;
	}
	color[u][c] = cm + c, dual[u][c] = dm;
}

int main() {
	int test, cs, n, e, i, u, v, cm, dm, color1, dual1, color0, dual0, colorM, dualM;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &e);
		for(i = 0; i < n; i++) G[i].clear();
		memset(color, -1, sizeof color);
		memset(dual, -1, sizeof dual);
		for(i = 0; i < e; i++) {
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cm = dm = 0;
		for(i = 0; i < n; i++) {
			if(color[i][0]==-1 && color[i][1]==-1) {
				solve(i, 1, -1);
				color1 = color[i][1], dual1 = dual[i][1];
				solve(i, 0, -1);
				color0 = color[i][0], dual0 = dual[i][0];

				if(color1 > color0) colorM = color0, dualM = dual0;
				else if(color1 < color0) colorM = color1, dualM = dual1;
				else if(dual1 > dual0) colorM = color1, dualM = dual1;
				else colorM = color0, dualM = dual0;

				cm += colorM, dm += dualM;
			}
		}
		printf("Case %d: %d %d %d\n", cs, cm, dm, e - dm);
	}
	return 0;
}
