#include <cstdio>

int main() {
	int test, cs, sum, amount, n;
	char what[8];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		sum = 0;
		printf("Case %d:\n", cs);
		while(n--) {
			scanf("%s", what);
			if(what[0] == 'd') {
				scanf("%d", &amount);
				sum += amount;
			}
			else printf("%d\n", sum);
		}
	}
	return 0;
}
