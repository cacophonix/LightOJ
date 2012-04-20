#include <cstdio>

int main() {
	char name[8];
	int test, cs, n;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %s", &n, name);
		if(name[0]=='A') printf("Case %d: %s\n", cs, (n % 3 != 1? "Alice" : "Bob"));
		else printf("Case %d: %s\n", cs, (n % 3 != 0? "Bob" : "Alice"));
	}
	return 0;
}
