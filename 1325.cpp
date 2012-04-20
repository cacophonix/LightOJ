/*
Shanks baby step giant step algorithm
for the equation: b = a^x % p where a, b, p known, finds x in range [0, p-2]
works only when p is an odd prime
*/

#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

struct Euclid {
	int x, y, d;
	Euclid() {}
	Euclid(int _x, int _y, int _d) : x(_x), y(_y), d(_d) {}
};

Euclid egcd(int a, int b) {
	if(!b) return Euclid(1, 0, a);
	Euclid r = egcd(b, a % b);
	return Euclid(r.y, r.x - a / b * r.y, r.d);
}

int modinv(int a, int m) {
	Euclid t = egcd(a, m);
	int r = t.x % m;
	return r < 0 ? r + m : r;
}

long long modexp(int a, int n, int m) {
	long long r = 1, b = a;
	while(n > 0) {
		if(n & 1) r = (r * b) % m;
		n >>= 1;
		b = (b * b) % m;
	}
	return r;
}

int shank(int a, int b, int p) {
	int i, j, m;
	long long c, aj, ami;
	map< long long, int > M;
	map< long long, int > :: iterator it;
	m = (int)ceil(sqrt((double)(p)));
	M.insert(make_pair(1, 0));
	for(j = 1, aj = 1; j < m; j++) {
		aj = (aj * a) % p;
		M.insert(make_pair(aj, j));
	}
	ami = modexp(modinv(a, p), m, p);
	for(c = b, i = 0; i < m; i++) {
		it = M.find(c);
		if(it != M.end()) return i * m + it->second;
		c = (c * ami) % p;
	}
	return 0;
}

int main() {
	int test, cs, a, b, p = 100000007;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &a, &b);
		printf("Case %d: %d\n", cs, shank(a, b, p));
	}
	return 0;
}