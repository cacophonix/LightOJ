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
const int INF = 0x7f7f7f7f;
const int MAX = 512;

int test, cs; // abar jodi case baraite vulish tor khobor ase...
vector< pii > G[MAX];
int flag[MAX], d[MAX];

void dijkstra(int s) {
	int w, u, v, e, i, sz;
	priority_queue< pii, vector< pii >, greater< pii > > Q;
	Q.push(pii(0, s));
	d[s] = 0;
	while(!Q.empty()) {
		w = Q.top().ff; u = Q.top().ss; Q.pop();
		if(d[u] < w) continue;
		sz = G[u].size();
		for(i = 0; i < sz; i++) {
			v = G[u][i].ss; e = G[u][i].ff;
			if(d[v] > _max(w, e)) {
				d[v] = _max(w, e);
				Q.push(pii(d[v], v));
			}
		}
	}
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n, m, u, v, w, i, t;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) G[i].clear();
		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			G[u].PB(pii(w, v));
			G[v].PB(pii(w, u));
		}
		scanf("%d", &t);
		memset(d, 0x7f, sizeof(d));
		dijkstra(t);
		printf("Case %d:\n", cs);
		for(i = 0; i < n; i++) {
			if(d[i] < INF) printf("%d\n", d[i]);
			else printf("Impossible\n");
		}
	}
	return 0;
}
