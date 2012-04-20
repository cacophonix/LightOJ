#include <cstdio>
#include <cstring>

typedef struct { int cnt, next[4]; } Trie;

Trie trie[800000];
int m[128], last, res;

void add(char *s) {
	int t, i, j;
	for(i = j = 0; s[i]; i++) {
		t = m[s[i]];
		if(trie[j].next[t] == -1) {
			trie[j].next[t] = ++last;
			memset(trie[last].next, -1, 4*sizeof(int));
			trie[last].cnt = 0;
		}
		j = trie[j].next[t];
		trie[j].cnt++;
		t = trie[j].cnt * (i + 1);
		if(t > res) res = t;
	}
}

int main() {
	int test, cs, i, n;
	char str[64];
	m['A'] = 0, m['C'] = 1, m['G'] = 2, m['T'] = 3;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		last = res = 0;
		memset(trie[0].next, -1, 4*sizeof(int));
		for(i = 0; i < n; i++) {
			scanf("%s", str);
			add(str);
		}
		printf("Case %d: %d\n", cs, res);
	}
	return 0;
}