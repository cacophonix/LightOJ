#include <cstdio>
#include <map>
using namespace std;

typedef unsigned int u32;
typedef long long int i64;
typedef pair< i64, int > state;

const int MAX = 64;

u32 nCr[MAX][MAX];
map< state, u32 > dp;
map< state, u32 > :: iterator it;

void calc() {
	for(int i = 0; i < MAX; i++) {
		nCr[i][0] = 1;
		for(int j = 1; j <= i; j++) nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
	}
}

u32 pwr(i64 n, int p) {
	u32 b = (u32)n, r = 1;
	while(p > 0) {
		if(p & 1) r = r * b;
		b = b * b;
		p >>= 1;
	}
	return r;
}

u32 solve(i64 n, int k) {
	if(n == 1) return 1;
	if((it = dp.find(state(n, k))) != dp.end()) return it->second;
	if(n & 1) {
		u32 res = solve(n - 1, k) + pwr(n, k);
		dp.insert(pair< state, u32 >(state(n, k), res));
		return res;
	}
	else {
		u32 res = solve(n >> 1, k) << 1;
		for(int i = 1; i <= k; i++) {
			res += nCr[k][i] * pwr(n >> 1, i) * solve(n >> 1, k - i);
		}
		dp.insert(pair< state, u32 >(state(n, k), res));
		return res;
	}
}

int main() {
	int test, cs, k;
	i64 n;
	calc();
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lld %d", &n, &k);
		dp.clear();
		printf("Case %d: %u\n", cs, solve(n, k));
	}
	return 0;
}