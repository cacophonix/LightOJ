#define _CRT_SECURE_NO_WARNINGS 1
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
const int MAX = 128;
const double BIG = 1e12;

typedef pair< int, int > point;
typedef struct { point u, v; double d; } segment;

segment s[MAX];
map< point, vector< int > > M;
double mat[MAX][MAX];

inline double dist(const point &a, const point &b) {
	return sqrt((double)sq(a.ff - b.ff) + (double)sq(a.ss - b.ss));
}

inline bool isleft(const point &a, const point &b, const point &c) {
	return (b.ff - a.ff) * (c.ss - a.ss) - (b.ss - a.ss) * (c.ff - a.ff) >= 0;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs, n, i, j, k, u, v;
	point bull;
	double ans;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &n, &bull.ff, &bull.ss);
		M.clear();
		for(i = 0; i < n; i++) {
			scanf("%d %d %d %d", &s[i].u.ff, &s[i].u.ss, &s[i].v.ff, &s[i].v.ss);
			if(!isleft(s[i].u, s[i].v, bull)) swap(s[i].u, s[i].v);
			s[i].d = dist(s[i].u, s[i].v);
			M[s[i].u].PB(i);
		}
		for(i = 0; i < n; i++) for(j = 0; j < n; j++) mat[i][j] = BIG;
		for(u = 0; u < n; u++) {
			for(j = 0; j < M[s[u].v].size(); j++) {
				v = M[s[u].v][j];
				if(isleft(s[u].u, s[u].v, s[v].v)) mat[u][v] = s[u].d + s[v].d;
			}
		}
		for(k = 0; k < n; k++)
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++)
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
		ans = BIG;
		for(i = 0; i < n; i++) ans = min(ans, mat[i][i]);
		if(fabs(ans - BIG) < EPS) printf("Case %d: %.8lf\n", cs, -1.0);
		else printf("Case %d: %.8lf\n", cs, ans + EPS);
	}
	return 0;
}