#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>

int main() {
	int test, cs, i, j, ca[26], cb[26];
	char a[128], b[128];
	test = atoi(gets(a));
	for(cs = 1; cs <= test; cs++) {
		gets(a);
		gets(b);
		memset(ca, 0, sizeof ca);
		memset(cb, 0, sizeof cb);
		for(i = 0; a[i]; i++) if(isalpha(a[i])) ca[tolower(a[i]) - 'a']++;
		for(i = 0; b[i]; i++) if(isalpha(b[i])) cb[tolower(b[i]) - 'a']++;
		for(i = j = 0; i < 26; i++) while(ca[i]--) a[j++] = i+'a'; a[j] = 0;
		for(i = j = 0; i < 26; i++) while(cb[i]--) b[j++] = i+'a'; b[j] = 0;
		if(!strcmp(a, b)) printf("Case %d: Yes\n", cs);
		else printf("Case %d: No\n", cs);
	}
	return 0;
}
