#include <cstdio>
#include <cstring>

#define i64 long long
#define BUFF 4096

i64 fact[21];
int cnt[26], len;
char str[26], buff[BUFF], *s, *ptr = buff, fnd;

void recur(i64 n, int d) {
	i64 a = 0, b, t;
	int i, j;
	if(d==len) { str[d] = fnd = 0; return; }
	for(i = 0; i < 26; i++) {
		if(!cnt[i]) continue;
		cnt[i]--;
		t = fact[len - d - 1];
		for(j = 0; j < 26; j++) t /= fact[cnt[j]];
		b = a + t;
		if(a <= n && n < b) {
			str[d] = i + 'a';
			recur(n-a, d+1);
			if(!fnd) return;
		}
		else {
			a = b;
			cnt[i]++;
		}
	}
}

inline int nextint() {
	register int ret = 0;
	while(*ptr<'0') ptr++;
	do { ret=ret*10 + *ptr++ - 48; } while(*ptr>='0');
	return ret;
}

inline char* nextstr() {
	while(*ptr<'a') ptr++; s = ptr++;
	while(*ptr>='a') ptr++; *ptr++ = 0;
	return s;
}

int main() {
	int i, test, cs = 1, n;
	fread(buff, 1, BUFF, stdin);
	for(fact[0] = i = 1; i < 21; i++) fact[i] = fact[i-1] * i;
	test = nextint();
	while(test--) {
		s = nextstr(); n = nextint(); fnd = 1;
		memset(cnt, 0, sizeof cnt);
		for(i = 0; s[i]; i++) cnt[s[i]-'a']++; len = i;
		recur(n-1, 0);
		if(!fnd) printf("Case %d: %s\n", cs++, str);
		else printf("Case %d: Impossible\n", cs++);
	}
	return 0;
}
