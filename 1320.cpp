#include <cstdio>
#include <set>
using namespace std;

typedef pair< int, int > Frac;
typedef pair< Frac, Frac > Point;

struct Line {
	int a, b, c; // ax + by = c
	Line() {}
	Line(int x1, int y1, int x2, int y2) {
		a = y1 - y2;
		b = x2 - x1;
		c = x1 * (y1 - y2) + y1 * (x2 - x1);
	}
};

int gcd(int a, int b) {
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}

Point intersect(const Line &p, const Line &q) {
	int d = p.a * q.b - q.a * p.b;
	if(d == 0) return Point(Frac(0, 0), Frac(0, 0));
	int dx = p.c * q.b - p.b * q.c;
	int dy = p.a * q.c - q.a * p.c;
	int g1 = gcd(d, dx), g2 = gcd(d, dy);
	return Point(Frac(dx/g1, d/g1), Frac(dy/g2, d/g2));
}

int main() {
	int test, cs, L, W, i, j, n, x1, y1, x2, y2, res;
	Line lines[128];
	Point ii;
	Frac x, y;
	set< Point > S;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &n, &L, &W);
		for(i = 0, res = 1; i < n; i++) {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			lines[i] = Line(x1, y1, x2, y2);
			S.clear();
			for(j = 0; j < i; j++) {
				ii = intersect(lines[i], lines[j]);
				x = ii.first, y = ii.second;
				if(x.first <= 0 || x.first >= L * x.second) continue;
				if(y.first <= 0 || y.first >= W * y.second) continue;
				S.insert(ii);
			}
			res += S.size() + 1;
		}
		printf("Case %d: %d\n", cs, res);
	}
	return 0;
}
