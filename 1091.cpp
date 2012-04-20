#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <cstring>
#include <cassert>

const int MAXN = 8;
const int MAXE = 64;

int to[MAXE], next[MAXE], used[MAXE];
int fin[MAXN], indeg[MAXN], outdeg[MAXN], stck[MAXN], vis[MAXN], G[MAXN][MAXN], deg[MAXN], fact[MAXN];
int nEdge, top, n, lines;

#define SPACE

inline void addEdge(int u, int v) {
	to[nEdge] = v; next[nEdge] = fin[u], fin[u] = nEdge++;
	to[nEdge] = u; next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool done() {
	int ind[MAXN], outd[MAXN], s[MAXN], k, u, v, i;
	k = top = 0;
	memcpy(ind, indeg, sizeof indeg);
	memcpy(outd, outdeg, sizeof outdeg);
	for(i = 0; i < n; i++) if(!outd[i]) s[k++] = i;
	if(k > 1) return false;
	while(k > 0) {
		u = s[--k];
		stck[top++] = u;
		for(i = 0; i < deg[u]; i++) {
			v = G[u][i];
			outd[v]--;
			if(!outd[v]) s[k++] = v;
		}
		if(k > 1) return false;
	}
	return top == n;
}

bool oncycle(int e) {
	int q[MAXN], st, en, u, v, i, j;
	used[e] = 1;
	j = u = to[e], st = en = 0;
	q[en++] = u;
	memset(vis, 0, sizeof vis);
	vis[u] = 1;
	while(st < en) {
		u = q[st++];
		for(i = fin[u]; i >= 0; i = next[i]) {
			if(used[i]) {
				v = to[i];
				vis[v]++;
				if(vis[v] == 1) q[en++] = v;
			}
		}
	}
	used[e] = 0;
	return vis[j] > 1;
}

void recur(int depth) {
	int i, j, u, v;
	if(done()) {
#ifdef SPACE
		for(j = 0; j < depth; j++) printf("    ");
#endif
		printf("print(");
		while(top--) {
			if(top) printf("%c, ", stck[top] + 'a');
			else printf("%c", stck[top] + 'a');
		}
		printf(");\n"); lines++;
		return;
	}
	for(i = 0; i < nEdge; i++) {
		if(!used[i] && !used[i^1] && !oncycle(i) && !oncycle(i^1)) {
			u = to[i ^ 1], v = to[i];
			used[i] = 1, indeg[v]++, outdeg[u]++, G[v][deg[v]++] = u;
#ifdef SPACE
			for(j = 0; j < depth; j++) printf("    ");
#endif
			printf("if(%c < %c)\n", u + 'a', v + 'a'); lines++;
			recur(depth + 1);
			indeg[v]--, outdeg[u]--, used[i] = 0, deg[v]--;

			u = to[i], v = to[i ^ 1];
			used[i ^ 1] = 1, indeg[v]++, outdeg[u]++, G[v][deg[v]++] = u;
#ifdef SPACE
			for(j = 0; j < depth; j++) printf("    ");
#endif
			printf("else\n"); lines++;
			recur(depth + 1);
			indeg[v]--, outdeg[u]--, used[i ^ 1] = 0, deg[v]--;

			break;
		}
	}
}

void print() {
	int i;
	printf("void print(");
	for(i = 0; i < n; i++) {
		if(!i) printf("int %c", i + 'a');
		else printf(", int %c", i + 'a');
	}
	printf(") {\n"); lines++;
#ifdef SPACE
	printf("    ");
#endif
	printf("printf(\"");
	for(i = 0; i < n; i++) {
		if(!i) printf("%%d");
		else printf(" %%d");
	}
	printf("\\n\"");
	for(i = 0; i < n; i++) printf(", %c", i + 'a');
	printf(");\n"); lines++;
	printf("}\n"); lines++;
	printf("void sort(");
	for(i = 0; i < n; i++) {
		if(!i) printf("int %c", i + 'a');
		else printf(", int %c", i + 'a');
	}
	printf(") {\n"); lines++;
	recur(1);
	printf("}\n"); lines++;
}

void calcfact() {
	fact[0] = fact[1] = 1;
	for(int i = 2; i <= 7; i++) fact[i] = i * fact[i-1];
}

int main() {
	int test, cs, u, v;
	//calcfact();
	//freopen("out.txt", "w", stdout);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		nEdge = 0;
		memset(fin, -1, sizeof fin);
		for(u = 0; u < n; u++)
			for(v = u + 1; v < n; v++)
				addEdge(u, v);
		printf("Case %d:\n", cs);
		lines = 0;
		print();
		//printf("%d lines, expected %d lines.\n", lines, 3 * fact[n] + 3);
	}
	return 0;
}