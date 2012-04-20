#include <cstdio>

int main() {
	int cs, test, n, cnt;
	char out[2][8] = {"even", "odd"};
	scanf("%d", &cs);
	for(test = 1; test <= cs; test++) {
		scanf("%d", &n);
		for(cnt = 0; n; cnt += (n & 1), n >>= 1);
		printf("Case %d: %s\n", test, out[cnt&1]);
	}
	return 0;
}
