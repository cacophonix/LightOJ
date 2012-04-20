#include <cstdio>

int main() {
	int test, cs, i, div, mod, digit;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &div, &digit);
		mod = i = 0;
		do {
			mod = (mod * 10 + digit) % div;
			i++;
		} while(mod);
		printf("Case %d: %d\n", cs, i);
	}
	return 0;
}