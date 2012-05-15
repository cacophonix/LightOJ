#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 2000;

int mat[2][MAX + 1], st[MAX];
char s[MAX + 2];

int calc(int *ht, int n) {
	int top = 1, i, ret = 0;
	ht[0] = st[0] = ht[++n] = 0;
	for(i = 1; i <= n; i++) {
		while(top > 1 && ht[st[top-1]] >= ht[i]) {
			ret = max(ret, ht[st[top-1]]*(i - st[top-2]-1));
			top--;
		}
		st[top++] = i;
	}
	return ret;
}

int main() {
	int test, cs, r, c, i, j, res;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &r, &c);
		gets(s);
		for(i = res = 0; i < r; i++) {
			gets(s);
			for(mat[i & 1][0] = 0, j = 1; j <= c; j++) {
				if(s[j - 1] == '1') mat[i & 1][j] = 0;
				else mat[i & 1][j] = i > 0? mat[(i - 1) & 1][j] + 1 : 1;
			}
			res = max(res, calc(mat[i & 1], c));
		}
		printf("Case %d: %d\n", cs, res);
	}
	return 0;
}