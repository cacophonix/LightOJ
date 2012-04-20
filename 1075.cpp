#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

typedef pair< string, int > psi;

const int MAX = 333;

map< string, int > M;
map< string, int > :: iterator it;
int deg[MAX], nxt[MAX];
char str[MAX][128];

inline int hash(char *s, int &n) {
	int ret; it = M.find(s);
	if(it == M.end()) {
		M.insert(psi(s, ret = n++));
		strcpy(str[ret], s);
	}
	else ret = it->second;
	return ret;
}

int main() {
	int test, cs, n, i, j, u, v;
	char name1[128], name2[128];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		M.clear();
		memset(deg, 0, sizeof deg);
		memset(nxt, -1, sizeof nxt);
		for(i = 1, j = 0; i < n; i++) {
			scanf("%s %s", name1, name2);
			u = hash(name1, j);
			v = hash(name2, j);
			deg[v]++; nxt[u] = v;
		}
		for(i = 0; i < j; i++) if(!deg[i]) break;
		printf("Case %d:\n", cs);
		for(; i >= 0; i = nxt[i]) printf("%s\n", str[i]);
		printf("\n");
	}
	return 0;
}