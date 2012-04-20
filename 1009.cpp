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
const int MAX = 20001;

vector< int > G[MAX];
set< int > S;
int color[MAX];

int bfs(int u) {
	int v, i, sz, cnt[3] = {0};
	queue< int > Q;
	Q.push(u);
	cnt[color[u] = 1]++;
	while(!Q.empty()) {
		u = Q.front(); Q.pop(); sz = G[u].size();
		for(i = 0; i < sz; i++) {
			v = G[u][i];
			if(color[v] == 0) {
				cnt[color[v] = 3 - color[u]]++;
				Q.push(v);
			}
		}
	}
	return _max(cnt[1], cnt[2]);
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs, n, u, v, i, cnt;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 1; i < MAX; i++) G[i].clear();
		S.clear(); SET(color); cnt = 0;
		for(i = 0; i < n; i++) {
			scanf("%d %d", &u, &v);
			color[u] = color[v] = 0;
			S.insert(u); S.insert(v);
			G[u].PB(v);
			G[v].PB(u);
		}
		for(set< int >::iterator it=S.begin(); it!=S.end(); it++) {
			if(color[*it]==0) {
				cnt += bfs(*it);
			}
		}
		printf("Case %d: %d\n", cs, cnt);
	}
	return 0;
}
