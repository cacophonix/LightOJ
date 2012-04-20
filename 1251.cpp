#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 16384;

int fmap[MAX], rmap[MAX];
int top, idx, components;
int Index[MAX], Low[MAX], Stack[MAX], Component[MAX];
char Valid[MAX], Onstack[MAX];
vector< int > G[MAX], C[MAX], S[MAX], res;

void tarjan(int u) {
	int v, i, sz = G[u].size();
	Index[u] = Low[u] = idx++;
	Stack[top++] = u;
	Onstack[u] = 1;
	for(i = 0; i < sz; i++) {
		v = G[u][i];
		if(Index[v] == -1) {
			tarjan(v);
			Low[u] = min(Low[u], Low[v]);
		}
		else if(Onstack[v]) Low[u] = min(Low[u], Index[v]);
	}
	if(Low[u] == Index[u]) {
		components++;
		do {
			v = Stack[--top];
			Onstack[v] = 0;
			Component[v] = components;
			C[components].push_back(v);
		} while(u != v);
	}
}

void findSCC(int n) {
	top = idx = components = 0;
	memset(Index, -1, (n + 1) * sizeof(int));
	for(int i = 1; i <= n; i++) if(Index[i] == -1) tarjan(i);
}

int main() {
	int test, cs, e, m, n, u, v, u1, v1, i, j, sz, impossible;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		memset(fmap, -1, sizeof fmap);
		scanf("%d %d", &e, &m);
		for(n = i = 0; i < e; i++) {
			scanf("%d %d", &u, &v);
			u1 = (u < 0)? -u : u;
			v1 = (v < 0)? -v : v;
			if(fmap[u1<<1]==-1) fmap[u1<<1] = ++n, rmap[n] = u1<<1;
			if(fmap[(u1<<1)+1]==-1) fmap[(u1<<1)+1] = ++n, rmap[n] = (u1<<1)+1;
			if(fmap[v1<<1]==-1) fmap[v1<<1] = ++n, rmap[n] = v1<<1;
			if(fmap[(v1<<1)+1]==-1) fmap[(v1<<1)+1] = ++n, rmap[n] = (v1<<1)+1;
			// !u -> v
			u1 = (u < 0)? (-u) << 1 : 1+(u << 1);
			v1 = (v < 0)? 1+((-v) << 1) : v << 1;
			G[fmap[u1]].push_back(fmap[v1]);
			// !v -> u
			v1 = (v < 0)? (-v) << 1 : 1+(v << 1);
			u1 = (u < 0)? 1+((-u) << 1) : u << 1;
			G[fmap[v1]].push_back(fmap[u1]);
		}
		findSCC(n);
		for(u = 1; u <= n; u++) {
			sz = G[u].size();
			for(i = 0; i < sz; i++) {
				v = G[u][i];
				if(Component[u] != Component[v]) S[Component[u]].push_back(Component[v]);
			}
		}
		memset(Valid, 1, (components+1) * sizeof(char));
		res.clear(); impossible = 0;
		for(i = 1; i <= m; i++) {
			if(fmap[i << 1] != -1) {
				u1 = i << 1; //+
				v1 = u1 + 1; //-
				if(Component[fmap[u1]] == Component[fmap[v1]]) {
					impossible = 1;
					break;
				}
			}
		}
		for(i = 1; i <= components && !impossible; i++) {
			if(!Valid[i]) continue;
			sz = S[i].size();
			for(j = 0; j < sz; j++) {
				u1 = S[i][j];
				if(!Valid[u1]) {
					Valid[i] = 0;
					break;
				}
			}
			if(!Valid[i]) continue;
			sz = C[i].size();
			for(j = 0; j < sz; j++) {
				u1 = rmap[C[i][j]];
				u = u1 >> 1;
				v1 = (u1 & 1)? u << 1 : (u << 1) + 1;
				Valid[Component[fmap[v1]]] = 0;
				if(!(u1 & 1)) res.push_back(u);
			}
		}
		if(impossible) printf("Case %d: No\n", cs);
		else {
			sz = res.size();
			printf("Case %d: Yes\n", cs);
			printf("%d", sz);
			sort(res.begin(), res.end());
			for(i = 0; i < sz; i++) printf(" %d", res[i]);
			printf("\n");
		}
		for(i = 1; i <= n; i++) G[i].clear();
		for(i = 1; i <= components; i++) C[i].clear(), S[i].clear();
	}
	return 0;
}