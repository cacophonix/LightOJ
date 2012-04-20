#include <cstdio>

typedef __int64 i64;

int main() {
	i64 n, m;
	int test, cs;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%I64d %I64d", &n, &m);
		printf("Case %d: %I64d\n", cs, m * (n >> 1));
	}
	return 0;
}
