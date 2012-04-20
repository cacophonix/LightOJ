#include <cstdio>
#include <cstdlib>

int main() {
	int r1, c1, r2, c2, test, cs = 1;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		if(((r1+c1)&1) != ((r2+c2)&1)) fprintf(stdout, "Case %d: impossible\n", cs++);
		else if(abs(r1-r2)==abs(c1-c2)) fprintf(stdout, "Case %d: 1\n", cs++);
		else fprintf(stdout, "Case %d: 2\n", cs++);
	}
	return 0;
}
