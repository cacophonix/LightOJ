#include <cstdio>

int main() {
	char s[35];
	int a[4], test, cs, t, k, i;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
		scanf("%s", s);
		k = t = 0;
		for(i = 0; s[i]; i++) {
			if(s[i] == '.') {
				//printf("%d %d\n", a[k], t);
				if(a[k] != t) break;
				t = 0;
				k++;
			}
			else {
				if(s[i] == '1') t = (t << 1) | 1;
				else t <<= 1;
			}
		}
		//if(!s[i]) printf("%d %d\n", a[k], t);
		if(!s[i] && a[k] == t) printf("Case %d: Yes\n", cs);
		else printf("Case %d: No\n", cs);
	}
	return 0;
}
