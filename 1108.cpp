/*
USER:
TASK:
ALGO:
*/
/*
#pragma warning (disable: 4786)
#pragma comment (linker, "/STACK:0x800000")
*/
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }

#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const int MAX = 1001;

int Stack[MAX], Onstack[MAX], top;
int Index[MAX], Lowlink[MAX], idx;
int Component[MAX], components;
vector< pii > G[MAX];
vector< int > SCC[MAX], DAG[MAX];
vector< int > buff;
bool hasNegCycle[MAX], vis[MAX];
int d[MAX];

void tarjan(int u) {
	int v, i;
	Index[u] = Lowlink[u] = idx++;
	Stack[top++] = u;
	Onstack[u] = 1;
	for(i = 0; i < SZ(G[u]); i++) {
		v = G[u][i].ff;
		if(Index[v]==-1) {
			tarjan(v);
			Lowlink[u] = min(Lowlink[u], Lowlink[v]);
		}
		else if(Onstack[v]) Lowlink[u] = min(Lowlink[u], Index[v]);
	}
	if(Lowlink[u] == Index[u]) {
		components++;
		SCC[components].clear();
		do {
			v = Stack[--top];
			Onstack[v] = 0;
			Component[v] = components;
			SCC[components].PB(v);
		} while(u != v);
	}
}

void findSCC(int n) {
	components = top = idx = 0;
	SET(Index); CLR(Onstack); MEM(Lowlink, 0x3f);
	for(int i = 1; i <= n; i++) if(Index[i]==-1) tarjan(i);
}

bool bellmanford(int x) {
	int i, j, k, sz, u, v, w;
	bool done = false;
	d[SCC[x][0]] = 0, sz = SZ(SCC[x]);
	for(k = 0; k < sz && !done; k++) {
		done = true;
		for(i = 0; i < sz; i++) {
			u = SCC[x][i];
			for(j = 0; j < SZ(G[u]); j++) {
				v = G[u][j].ff; w = G[u][j].ss;
				if(Component[u] == Component[v]) {
					if(d[u] + w < d[v]) {
						d[v] = d[u] + w;
						done = false;
					}
				}
			}
		}
	}
	return (hasNegCycle[x] = !done);
}

bool solve(int u) {
	int i, sz = SZ(DAG[u]);
	if(vis[u]) return hasNegCycle[u]; vis[u] = 1;
	if(hasNegCycle[u]) return hasNegCycle[u];
	for(i = 0; i < sz; i++) hasNegCycle[u] |= solve(DAG[u][i]);
	return hasNegCycle[u];
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs, n, e, i, j, u, v, w;
	bool possible;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &e);
		for(i = 1; i <= n; i++) G[i].clear();
		MEM(d, 0x3f);
		for(i = 0; i < e; i++) {
			scanf("%d %d %d", &u, &v, &w);
			u++; v++;
			G[u].PB(pii(v, w));
		}
		findSCC(n);
		possible = false;
		for(i = 1; i <= components; i++) {
			possible |= bellmanford(i);
		}
		if(!possible) {
			printf("Case %d: impossible\n", cs);
			continue;
		}
		for(i = 1; i <= components; i++) DAG[i].clear();
		for(u = 1; u <= n; u++) {
			for(i = 0; i < SZ(G[u]); i++) {
				v = G[u][i].ff;
				if(Component[u] != Component[v]) DAG[Component[u]].PB(Component[v]);
			}
		}
		CLR(vis);
		for(i = 1; i <= components; i++) solve(i);
		buff.clear();
		for(i = 1; i <= components; i++) {
			if(hasNegCycle[i]) {
				for(j = 0; j < SZ(SCC[i]); j++) {
					buff.PB(SCC[i][j]-1);
				}
			}
		}
		sort(buff.begin(), buff.end());
		printf("Case %d:", cs);
		for(i = 0; i < SZ(buff); i++) printf(" %d", buff[i]); printf("\n");
	}
	return 0;
}
