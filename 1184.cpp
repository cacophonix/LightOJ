#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAX = 50;

typedef struct { int h, age, dev; } Person;

Person man[MAX], woman[MAX];
vector< int > G[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX];
 
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
	memset(Left, -1, sizeof Left);
	memset(Right, -1, sizeof Right);
	do {
		done = true;
		memset(visited, 0, sizeof visited);
		for(i=0; i<n; i++) {
			if(Left[i]==-1 && dfs(i)) {
				done = false;
			}
		}
	} while(!done);
	for(i=0; i<n; i++) ret += (Left[i]!=-1);
	return ret;
}

int main() {
	int test, cs, i, j, m, w;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &m, &w);
		for(i = 0; i < m; i++) scanf("%d %d %d", &man[i].h, &man[i].age, &man[i].dev);
		for(i = 0; i < w; i++) scanf("%d %d %d", &woman[i].h, &woman[i].age, &woman[i].dev);
		for(i = 0; i < m; i++) {
			G[i].clear();
			for(j = 0; j < w; j++) {
				if(abs(man[i].h - woman[j].h) <= 12 && abs(man[i].age - woman[j].age) <= 5 && man[i].dev == woman[j].dev) {
					G[i].push_back(j);
				}
			}
		}
		printf("Case %d: %d\n", cs, match(m));
	}
	return 0;
}