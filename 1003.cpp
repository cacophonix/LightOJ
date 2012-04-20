#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;

typedef pair< string, int > psi;

const int MAXE = 10000;
const int MAXN = 10000;

map< string, int > M;
map< string, int >::iterator it;
int to[MAXE], next[MAXE], fin[MAXE], cur;
int stck[MAXN], top;
char flag[MAXN];

inline int hash(char *s, int &n) {
	int ret;
	it = M.find(s);
	if(it == M.end()) M.insert(pair< string, int >(s, ret = n++));
	else ret = it->second;
	return ret;
}

#define addEdge(u,v) to[cur]=v;next[cur]=fin[u];fin[u]=cur++;

bool dfs(int u) {
	int v, i;
	flag[u] = 1, top = 1, stck[0] = u;
	while(top--) {
		u = stck[top];
		if(flag[u] == 1) stck[top++] = u, flag[u] = 2;
		else if(flag[u] == 2) {
			flag[u] = 3;
			continue;
		}
		for(i = fin[u]; i >= 0; i = next[i]) {
			v = to[i];
			if(!flag[v]) {
				flag[v] = 1;
				stck[top++] = v;
			}
			else if(flag[v] == 2) return false;
		}
	}
	return true;
}

int main() {
	char name1[16], name2[16];
	int cs, test, i, n, k, u, v;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		memset(fin, -1, sizeof(fin));
		M.clear(); k = cur = 0;
		for(i = 0; i < n; i++) {
			scanf("%s %s", name1, name2);
			u = hash(name1, k);
			v = hash(name2, k);
			addEdge(u, v);
		}
		memset(flag, 0, sizeof(char)*k);
		for(i = 0; i < k; i++) {
			if(!flag[i]) {
				if(!dfs(i)) break;
			}
		}
		if(i == k) printf("Case %d: Yes\n", cs);
		else printf("Case %d: No\n", cs);
	}
	return 0;
}
