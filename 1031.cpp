#include <cassert>
#include <cctype>
#include <climits>
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

i64 a[101], dp[101][101];

i64 solve(int i, int j) {
	if(i > j) return 0;
	i64 &ret = dp[i][j], s; int k;
	if(ret != -1) return ret;
	ret = 1, ret <<= 60, ret = -ret, s = a[j] - a[i-1];
	for(k = i; k <= j; k++) {
		ret = _max(ret, s-solve(k+1, j));
	}
	for(k = j; k >= i; k--) {
		ret = _max(ret, s-solve(i, k-1));
	}
	return ret;
}

int main() {
	int n, i, test, cs; i64 ret;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			a[i] += a[i-1];
		}
		SET(dp);
		ret = solve(1, n);
		printf("Case %d: %lld\n", cs, (ret<<1)-a[n]);
	}
	return 0;
}
