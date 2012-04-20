#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct { int next[52]; } Trie;

const int MAX = 33792;

Trie trie[MAX];
int cnt[MAX], last;

int func(char *s, int len, int chk) {
	int i, j, k;
	for(i = j = 0; i < len; i++) {
		if(s[i] > 'Z') k = s[i] - 'a' + 26;
		else k = s[i] - 'A';
		if(trie[j].next[k] == -1) {
			if(chk) return -1;
			trie[j].next[k] = ++last;
			memset(trie[last].next, -1, sizeof(int) * 52);
			cnt[last] = 0;
		}
		j = trie[j].next[k];
	}
	return j;
}

int main() {
	int test, cs, i, j, len, n, q, res;
	char str[128], line[10009], *p;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		gets(str);
		last = 0;
		memset(trie[0].next, -1, sizeof(int) * 52);
		for(i = 0; i < n; i++) {
			len = strlen(gets(str));
			if(len > 2) sort(str + 1, str + len - 1);
			j = func(str, len, 0);
			cnt[j]++;
		}
		printf("Case %d:\n", cs);
		scanf("%d", &q);
		gets(str);
		while(q--) {
			gets(line);
			res = 1;
			p = strtok(line, " ");
			while(p) {
				len = strlen(p);
				if(len > 2) sort(p + 1, p + len - 1);
				j = func(p, len, 1);
				if(j != -1) res *= cnt[j];
				else { res = 0; break; }
				p = strtok(0, " ");
			}
			printf("%d\n", res);
		}
	}
	return 0;
}