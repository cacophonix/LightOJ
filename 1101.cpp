#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;
typedef pair< int, pii > edge;

const int MAX = 1 << 16;
const int LOG = 16;

vector< edge > E;
vector< pii > G[MAX];
int N, flagv, root[MAX], vis[MAX], T[MAX], L[MAX];
int P[MAX][LOG], mx[MAX][LOG];

int find(int u) {
	if(u != root[u]) root[u] = find(root[u]);
	return root[u];
}

int dfs(int u, int p, int d) {
	int i, v, w, k, sz = G[u].size();
	T[u] = p; k = L[u] = d; vis[u] = flagv;
	for(i = 0; i < sz; i++) {
		v = G[u][i].first;
		w = G[u][i].second;
		if(vis[v] != flagv) {
			k = max(k, dfs(v, u, d + 1));
			P[v][0] = u;
			mx[v][0] = w;
		}
	}
	return k;
}

void preProcess() {
	int i, j, D;
	P[1][0] = -1, mx[1][0] = 0;
	D = dfs(1, -1, 0);
	for(i = 1; i <= N; i++) {
		for(j = 1; (1 << j) <= D; j++) {
			P[i][j] = -1;
			mx[i][j] = 0;
		}
	}
	for(j = 1; (1 << j) <= D; j++) {
		for(i = 1; i <= N; i++) {
			if(P[i][j - 1] != -1) {
				P[i][j] = P[P[i][j - 1]][j - 1];
				mx[i][j] = max(mx[i][j-1], mx[P[i][j-1]][j-1]);
			}
		}
	}
}

int query(int p, int q) {
	int tmp, lg, i, mxv = 0;
	if(L[p] < L[q]) swap(p, q);
	for(lg = 1; (1 << lg) <= L[p]; lg++); lg--;
	for(i = lg; i >= 0; i--) {
		if(L[p] - (1 << i) >= L[q]) {
			mxv = max(mxv, mx[p][i]);
			p = P[p][i];
		}
	}
	if(p == q) return mxv;
	for(i = lg; i >= 0; i--) {
		if(P[p][i] != -1 && P[p][i] != P[q][i]) {
			mxv = max(mxv, max(mx[p][i], mx[q][i]));
			p = P[p][i];
			q = P[q][i];
		}
	}
	mxv = max(mxv, max(mx[p][0], mx[q][0]));
	return mxv;
}

int main() {
	int test, cs, n, m, i, j, u, v, pu, pv, w;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &m);
		E.resize(m); flagv = cs; N = n;
		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			E[i] = edge(w, pii(u, v));
		}
		sort(E.begin(), E.end());
		for(u = 1; u <= n; u++) {
			root[u] = u;
			G[u].clear();
		}
		for(i = j = 0; i < m && j < n-1; i++) {
			u = E[i].second.first, v = E[i].second.second, w = E[i].first;
			pu = find(u), pv = find(v);
			if(pu != pv) {
				G[u].push_back(pii(v, w));
				G[v].push_back(pii(u, w));
				j++; root[pu] = root[pv];
			}
		}
		preProcess();
		printf("Case %d:\n", cs);
		scanf("%d", &m);
		while(m--) {
			scanf("%d %d", &u, &v);
			printf("%d\n", query(u, v));
		}
	}
	return 0;
}