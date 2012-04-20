#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100032;
const int MAXL = 20;

typedef pair< int, int > pii;

int N, flagv, vis[MAXN], T[MAXN], L[MAXN];
int P[MAXN][MAXL], mx[MAXN][MAXL], mn[MAXN][MAXL];
vector< pii > G[MAXN];

void dfs(int u, int p, int d) {
	int i, v, w, sz = G[u].size();
	T[u] = p; L[u] = d; vis[u] = flagv;
	for(i = 0; i < sz; i++) {
		v = G[u][i].first;
		w = G[u][i].second;
		if(vis[v] != flagv) {
			dfs(v, u, d + 1);
			P[v][0] = u;
			mx[v][0] = mn[v][0] = w;
		}
	}
}

void process() {
	int i, j;
	for(i = 1; i <= N; i++) {
		for(j = 0; 1 << j < N; j++) {
			P[i][j] = -1;
			mx[i][j] = INT_MIN;
			mn[i][j] = INT_MAX;
		}
	}
	dfs(1, -1, 0);
	for(j = 1; 1 << j < N; j++) {
		for(i = 1; i <= N; i++) {
			if(P[i][j - 1] != -1) {
				P[i][j] = P[P[i][j - 1]][j - 1];
				mx[i][j] = max(mx[i][j-1], mx[P[i][j-1]][j-1]);
				mn[i][j] = min(mn[i][j-1], mn[P[i][j-1]][j-1]);
			}
		}
	}
}

int query(int p, int q, int &mxv, int &mnv) {
	int tmp, lg, i;
	mxv = INT_MIN, mnv = INT_MAX;
	if(L[p] < L[q]) swap(p, q);
	for(lg = 1; (1 << lg) <= L[p]; lg++); lg--;
	for(i = lg; i >= 0; i--) {
		if(L[p] - (1 << i) >= L[q]) {
			mxv = max(mxv, mx[p][i]);
			mnv = min(mnv, mn[p][i]);
			p = P[p][i];
		}
	}
	if(p == q) return p;
	for(i = lg; i >= 0; i--) {
		if(P[p][i] != -1 && P[p][i] != P[q][i]) {
			mxv = max(mxv, max(mx[p][i], mx[q][i]));
			mnv = min(mnv, min(mn[p][i], mn[q][i]));
			p = P[p][i];
			q = P[q][i];
		}
	}
	mxv = max(mxv, max(mx[p][0], mx[q][0]));
	mnv = min(mnv, min(mn[p][0], mn[q][0]));
	return T[p];
}

int main() {
	int test, cs, q, i, u, v, w, mxv, mnv;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		flagv = cs;
		scanf("%d", &N);
		for(i = 1; i <= N; i++) G[i].clear();
		for(i = 1; i < N; i++) {
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(pii(v, w));
			G[v].push_back(pii(u, w));
		}
		process();
		printf("Case %d:\n", cs);
		scanf("%d", &q);
		while(q--) {
			scanf("%d %d", &u, &v);
			u = query(u, v, mxv, mnv);
			printf("%d %d\n", mnv, mxv);
		}
	}
	return 0;
}