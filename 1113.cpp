#include <cstdio>
#include <cstring>

char str[100][55];
int fs[100], ftop;
int bs[100], btop;
char comm[10], id;

int main() {
	int test, cs, curr;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		ftop = btop = id = curr = 0;
		strcpy(str[id++], "http://www.lightoj.com/");
		printf("Case %d:\n", cs);
		while(scanf("%s", comm)==1 && comm[0]!='Q') {
			switch(comm[0]) {
				case 'B':
					if(!btop) puts("Ignored");
					else {
						fs[ftop++] = curr;
						curr = bs[--btop];
						puts(str[curr]);
					}
				break;
				case 'F':
					if(!ftop) puts("Ignored");
					else {
						bs[btop++] = curr;
						curr = fs[--ftop];
						puts(str[curr]);
					}
				break;
				case 'V':
					ftop = 0;
					bs[btop++] = curr;
					scanf("%s", str[curr = id++]);
					puts(str[curr]);
				break;
			}
		}
	}
	return 0;
}
