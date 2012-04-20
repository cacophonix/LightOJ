#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int test, cs, n, k, i;
	char str[27];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &k); printf("Case %d:\n", cs);
		for(i = 0; i < n; i++) str[i] = 'A'+i; str[i] = 0;
		do puts(str); while(--k && next_permutation(str, str + n));
	}
	return 0;
}
