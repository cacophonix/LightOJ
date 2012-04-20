#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 30009;

int calc(int *ht, int n) {
	int top = 1, st[MAX], i, ret = 0;
	ht[0] = st[0] = ht[++n] = 0;
	for(i = 1; i <= n; i++) {
		while(top > 1 && ht[st[top-1]] >= ht[i]) {
			ret = max(ret, ht[st[top-1]] * (i - st[top-2]-1));
			top--;
		}
		st[top++] = i;
	}
	return ret;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n, i, ht[MAX], test, cs = 1;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		for(i = 1; i <= n; i++) scanf("%d", &ht[i]);
		printf("Case %d: %d\n", cs++, calc(ht, n));
	}
	return 0;
}
