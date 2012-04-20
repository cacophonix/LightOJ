#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 30001;

typedef pair<int,int> pii;

vector< pii > G[MAX];
int d[MAX], p[MAX];

int bfs1(int u, int n) {
	int v, w, i, sz, mx, idx;
	queue< int > Q;
	memset(d, -1, n*sizeof(int));
	d[u] = 0;
	Q.push(u);
	while(!Q.empty()) {
		u = Q.front(); Q.pop();
		sz = G[u].size();
		for(i = 0; i < sz; i++) {
			v = G[u][i].first;
			w = G[u][i].second;
			if(d[v] == -1) {
				d[v] = d[u] + w;
				Q.push(v);
			}
		}
	}
	mx = d[u], idx = u;
	for(i = 0; i < n; i++) {
		if(d[i] > mx) {
			mx = d[i];
			idx = i;
		}
	}
	return idx;
}

void bfs2(int u, int n) {
	int i, sz, v, w;
	queue< int > Q;
	Q.push(u);
	memset(p, -1, n*sizeof(int));
	p[u] = 0;
	while(!Q.empty()) {
		u = Q.front(); Q.pop();
		if(p[u] > d[u]) d[u] = p[u];
		sz = G[u].size();
		for(i = 0; i < sz; i++) {
			v = G[u][i].first;
			w = G[u][i].second;
			if(p[v] == -1) {
				p[v] = p[u] + w;
				Q.push(v);
			}
		}
	}
}

int main() {
	int test, cs, i, u, v, w, n;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) G[i].clear();
		for(i = 1; i < n; i++) {
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(make_pair(v, w));
			G[v].push_back(make_pair(u, w));
		}
		u = bfs1(0, n);
		v = bfs1(u, n);
		bfs2(v, n);
		printf("Case %d:\n", cs);
		for(i = 0; i < n; i++) printf("%d\n", d[i]);
	}
	return 0;
}
