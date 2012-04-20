#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;
typedef pair< int, pii > edge;

const int INF = 0x3f3f3f3f;
const int MAX = 16;

int mat[MAX][MAX], deg[MAX];
int dp[1 << MAX], n;
vector< edge > E;

int solve(int mask) {
	if(!mask) return 0;
	if(dp[mask] != -1) return dp[mask];
	int &ret = dp[mask]; ret = INF;
	int i, sz = E.size(), nmask;
	for(i = 0; i < sz; i++) {
		if((mask & (1<<E[i].second.first)) && (mask & (1<<E[i].second.second))) {
			nmask = mask & ~(1<<E[i].second.first) & ~(1<<E[i].second.second);
			ret = min(ret, E[i].first + solve(nmask));
		}
	}
	return ret;
}

int main() {
	int test, cs, e, total, odd, i, j, k, u, v, w, mask;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &e);
		memset(mat, 0x3f, sizeof mat);
		memset(deg, 0, sizeof deg);
		for(i = 1; i <= n; i++) mat[i][i] = 0;
		for(i = total = 0; i < e; i++) {
			scanf("%d %d %d", &u, &v, &w);
			total += w; deg[u]++; deg[v]++;
			mat[u][v] = mat[v][u] = min(mat[u][v], w);
		}
		for(odd = mask = 0, i = 1; i <= n; i++) {
			if(deg[i] & 1) odd++, mask |= (1 << i);
		}
		if(!odd) {
			printf("Case %d: %d\n", cs, total);
			continue;
		}
		for(k = 1; k <= n; k++)
			for(i = 1; i <= n; i++)
				for(j = 1; j <= n; j++)
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
		E.clear();
		for(i = 1; i < n; i++)
			if(deg[i]&1) for(j = i+1; j <= n; j++)
				if(deg[j]&1) E.push_back(edge(mat[i][j], pii(i, j)));
		if(E.size() == 1) {
			printf("Case %d: %d\n", cs, total + E[0].first);
			continue;
		}
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", cs, total + solve(mask));
	}
	return 0;
}
