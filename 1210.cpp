/*
TASK: 1210
ALGO: scc
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
const int INF = 0x7f7f7f7f;
const int MAX = 20009;

int indeg[MAX], outdeg[MAX];

vector< int > G[MAX], R[MAX];
int stck[MAX], top;
char vis[MAX];
int compo[MAX], cnt;

void dfs1(int u) {
	int i, v;
	for(i = 0; i < SZ(G[u]); i++) {
		v = G[u][i];
		if(!vis[v]) {
			vis[v] = 1;
			dfs1(v);
		}
	}
	stck[top++] = u;
}

void dfs2(int u) {
	int i, v;
	for(i = 0; i < SZ(R[u]); i++) {
		v = R[u][i];
		if(!vis[v]) {
			vis[v] = 1;
			dfs2(v);
		}
	}
	compo[u] = cnt;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs = 1, n, e, i, u, v, cnt1, cnt2, j;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d", &n, &e);
		
		for(i = 0; i < n; i++) {
			G[i].clear();
			R[i].clear();
		}
		
		for(i = 0; i < e; i++) {
			scanf("%d %d", &u, &v);
			u--; v--;
			G[u].PB(v);
			R[v].PB(u);
		}
		
		CLR(vis);
		top = 0;
		for(i = 0; i < n; i++) {
			if(!vis[i]) {
				vis[i] = 1;
				dfs1(i);
			}
		}
		
		cnt = 0;
		CLR(vis);
		while(top--) {
			i = stck[top];
			if(!vis[i]) {
				vis[i] = 1;
				dfs2(i);
				cnt++;
			}
		}
		if(cnt == 1) {
			printf("Case %d: 0\n", cs++);
			continue;
		}
		CLR(indeg);
		CLR(outdeg);
		for(i = 0; i < n; i++) {
			for(j = 0; j < SZ(G[i]); j++) {
				v = G[i][j];
				if(compo[i] != compo[v]) {
					outdeg[compo[i]]++;
					indeg[compo[v]]++;
				}
			}
		}
		
		cnt1 = cnt2 = 0;
		for(i = 0; i < cnt; i++) {
			if(!indeg[i]) cnt1++;
			if(!outdeg[i]) cnt2++;
		}
		printf("Case %d: %d\n", cs++, _max(cnt1, cnt2));
	}
	return 0;
}
