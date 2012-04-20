#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string, int> psi;
typedef pair<int, int> pii;
typedef pair<int, pii> Edge;

const int MAX = 128;

map<string, int> M;
map<string, int>::iterator it;
vector<Edge> G;
int root[MAX];

int find(int u) {
	if(u != root[u]) root[u] = find(root[u]);
	return root[u];
}

int hash(char *s, int &n) {
	int ret; it = M.find(s);
	if(it != M.end()) ret = it->second;
	else M.insert(psi(s, ret=++n));
	return ret;
}

int main() {
	int test, cs, i, e, u, v, n, w, t;
	char name1[64], name2[64];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &e);
		G.clear();
		M.clear();
		for(i = n = 0; i < e; i++) {
			scanf("%s %s %d", name1, name2, &w);
			u = hash(name1, n);
			v = hash(name2, n);
			G.push_back(Edge(w,pii(u, v)));
		}
		for(i = 1; i <= n; i++) root[i] = i;
		sort(G.begin(), G.end());
		for(i = t = w = 0; t+1 < n && i < e; i++) {
			u = find(G[i].second.first);
			v = find(G[i].second.second);
			if(u != v) {
				w += G[i].first;
				root[u] = root[v];
				t++;
			}
		}
		if(t != n-1) printf("Case %d: Impossible\n", cs);
		else printf("Case %d: %d\n", cs, w);
	}
	return 0;
}
