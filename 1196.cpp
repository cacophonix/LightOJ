/*
USER: zobayer
TASK: 1196
ALGO: binary search
*/
/*
// VC6 Mumbo Jumbo
#pragma warning (disable: 4786)
#pragma comment (linker, "/STACK:0x8000000")
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
const int MAX = 100009;

typedef struct { i64 x, y; } point;

point C[MAX], qp;

inline i64 triArea2(const point &a, const point &b, const point &c) {
	return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y);
}

inline bool inConvexPoly(int nc, const point &p) {
	int st = 1, en = nc - 1, mid;
	while(en - st > 1) {
		mid = (st + en)>>1;
		if(triArea2(C[0], C[mid], p) < 0) en = mid;
		else st = mid;
	}
	if(triArea2(C[0], C[st], p) < 0) return false;
	if(triArea2(C[st], C[en], p) < 0) return false;
	if(triArea2(C[en], C[0], p) < 0) return false;
	return true;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs = 1, i, n, q;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%lld %lld", &C[i].x, &C[i].y);
		printf("Case %d:\n", cs++); scanf("%d", &q);
		while(q--) {
			scanf("%lld %lld", &qp.x, &qp.y);
			if(inConvexPoly(n, qp)) puts("y");
			else puts("n");
		}
	}
	return 0;
}
