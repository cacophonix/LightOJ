#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 512;

vector< int > G[MAX], LM[128], HM[128], LF[128], HF[128];
int Left[MAX], Right[MAX];
bool visited[MAX];
 
bool dfs(int u) {
	if(visited[u]) return false;
	visited[u] = true;
	int len = G[u].size(), i, v;
	for(i=0; i<len; i++) {
		v = G[u][i];
		if(Right[v]==-1) {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	for(i=0; i<len; i++) {
		v = G[u][i];
		if(dfs(Right[v])) {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	return false;
}
 
int match(int n) {
	int i, ret = 0;
	bool done;
	memset(Right, -1, sizeof Right);
	memset(Left, -1, sizeof Left);
	do {
		done = true;
		memset(visited, 0, sizeof visited);
		for(i=1; i<=n; i++) {
			if(Left[i]==-1 && dfs(i)) {
				done = false;
			}
		}
	} while(!done);
	for(i=1; i<=n; i++) ret += (Left[i]!=-1);
	return ret;
}

int main() {
	int test, cs, m, f, c, i, u, v, ans;
	char su[8], sv[8];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &m, &f, &c);
		for(i = 1; i <= c; i++) G[i].clear();
		for(i = 1; i <= m; i++) LM[i].clear(), HM[i].clear();
		for(i = 1; i <= f; i++) LF[i].clear(), HF[i].clear();
		for(i = 1; i <= c; i++) {
			scanf("%s %s", su, sv);
			if(su[0] == 'M') {
				u = atoi(&su[1]);
				LM[u].push_back(i);
				v = atoi(&sv[1]);
				HF[v].push_back(i);
			}
			else {
				u = atoi(&su[1]);
				LF[u].push_back(i);
				v = atoi(&sv[1]);
				HM[v].push_back(i);
			}
		}
		for(i = 1; i <= m; i++) {
			for(u = 0; u < LM[i].size(); u++) {
				for(v = 0; v < HM[i].size(); v++) {
					G[LM[i][u]].push_back(HM[i][v]);
				}
			}
		}
		for(i = 1; i <= f; i++) {
			for(u = 0; u < HF[i].size(); u++) {
				for(v = 0; v < LF[i].size(); v++) {
					G[HF[i][u]].push_back(LF[i][v]);
				}
			}
		}
		ans = c - match(c);
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}