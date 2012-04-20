#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 1000;

int mapp[MAX], stck[MAX], top;
int compo[MAX], ncompo;
int flag[MAX], vis[MAX], flagv, done;

vector< int > G[MAX], R[MAX], S[MAX];

void dfsF(int u) {
	int i, v, sz = G[u].size();
	flag[u] = flagv;
	for(i = 0; i < sz; i++) {
		v = G[u][i];
		if(flag[v] != flagv) dfsF(v);
	}
	stck[top++] = u;
}

void dfsR(int u) {
	int i, v, sz = R[u].size();
	flag[u] = flagv;
	compo[u] = ncompo;
	for(i = 0; i < sz; i++) {
		v = R[u][i];
		if(flag[v] != flagv) dfsR(v);
	}
}

void dfs(int u) {
	if(S[u].size() > 1) {
		done = 1;
		return;
	}
	vis[u] = flagv;
	if(!S[u].empty()) dfs(S[u][0]);
}

int main() {
	int child, wish, u, v, n, test, cs, i, sz;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		memset(mapp, -1, sizeof mapp);
		for(u = 0; u < MAX; u++) {
			G[u].clear();
			R[u].clear();
			S[u].clear();
		}
		mapp[0] = 0; n = 1;
		scanf("%d", &child);
		while(child--) {
			scanf("%d", &wish);
			while(wish--) {
				scanf("%d %d", &u, &v);
				if(mapp[u] == -1) mapp[u] = n++;
				if(mapp[v] == -1) mapp[v] = n++;
				//printf("%d -> %d, %d -> %d\n", u, mapp[u], v, mapp[v]);
				u = mapp[u], v = mapp[v];
				G[u].push_back(v);
				R[v].push_back(u);
			}
		}
		flagv = cs << 1, top = 0;
		for(u = 0; u < n; u++) if(flag[u] != flagv) dfsF(u);
		flagv++, ncompo = 0;
		while(top--) {
			u = stck[top];
			if(flag[u] != flagv) {
				dfsR(u);
				ncompo++;
			}
		}
		for(u = 0; u < n; u++) {
			//printf("%d in component %d\n", u, compo[u]);
			sz = G[u].size();
			for(i = 0; i < sz; i++) {
				v = G[u][i];
				if(compo[u] != compo[v]) S[compo[u]].push_back(compo[v]);
			}
		}
		done = 0;
		dfs(compo[0]);
		if(!done) {
			for(u = 0; u < ncompo; u++) {
				if(vis[u] != flagv) {
					done = 1;
					break;
				}
			}
		}
		if(!done) printf("Case %d: YES\n", cs);
		else printf("Case %d: NO\n", cs);
	}
	return 0;
}