#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long i64;

const int MAX = 100001;
const i64 MOD = 1000007;

int K, C;
i64 a[MAX], c[MAX];

void gen(int n) {
	for(int i = 1; i < n; i++) {
		a[i] = (K*a[i - 1] + C) % MOD;
	}
}

i64 GetDiffSum(int n) {
	i64 sum = 0;
	int i, lt, rt;
	for(i = 0; i < n; i++) {
		lt = i;
		rt = n-i;
		sum += a[i] * lt - (i > 0? c[i-1] : 0);
		sum += c[n-1] - (i > 0? c[i-1] : 0) - a[i] * rt;
	}
	return sum >> 1;
}

int main() {
	int cs, test, n, i;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d %lld", &K, &C, &n, a);
		gen(n);
		sort(a, a + n);
		for(c[0] = a[0], i = 1; i < n; i++) c[i] = c[i-1] + a[i];
		printf("Case %d: %lld\n", cs, GetDiffSum(n));
	}
	return 0;
}
