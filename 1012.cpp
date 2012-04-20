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

int test, cs, R, C;
char grid[22][22];
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

void find(int &r, int &c) {
	int i, j;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(grid[i][j] == '@') {
				r = i; c = j;
				return;
			}
		}
	}
}

bool valid(int r, int c) {
	return (0 <= r && r < R && 0 <= c && c < C);
}

int bfs(int ur, int uc) {
	int vr, vc, k, ret = 1;
	queue< int > Q;
	Q.push(ur); Q.push(uc);
	grid[ur][uc] = '#';
	while(!Q.empty()) {
		ur = Q.front(); Q.pop();
		uc = Q.front(); Q.pop();
		for(k = 0; k < 4; k++) {
			vr = ur + dr[k];
			vc = uc + dc[k];
			if(valid(vr, vc) && grid[vr][vc] == '.') {
				ret++; grid[vr][vc] = '#';
				Q.push(vr); Q.push(vc);
			}
		}
	}
	return ret;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int i, j;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &C, &R);
		for(i = 0; i < R; i++) scanf("%s", grid[i]);
		find(i, j);
		printf("Case %d: %d\n", cs, bfs(i, j));
	}
	return 0;
}
