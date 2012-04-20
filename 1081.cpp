#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 512;

int a[MAX][MAX], n;
int dp[MAX][MAX][10];

inline int val(int i) {
	return a[i / n][i % n];
}

void init() {
	int i, j, k, p[4], m;
	for(i = k = 0; i < n; i++)
		for(j = 0; j < n; j++)
			dp[i][j][0] = k++;
	for(k = 1; (1 << k) <= n; k++) {
		for(i = 0; i + (1 << k) - 1 < n; i++) {
			for(j = 0; j + (1 << k) - 1 < n; j++) {
				p[0] = dp[i][j][k-1];
				p[1] = dp[i][j + (1 << (k-1))][k-1];
				p[2] = dp[i + (1 << (k-1))][j][k-1];
				p[3] = dp[i + (1 << (k-1))][j + (1 << (k-1))][k-1];
				dp[i][j][k] = p[0];
				for(m = 1; m < 4; m++) {
					if(val(dp[i][j][k]) < val(p[m])) {
						dp[i][j][k] = p[m];
					}
				}
			}
		}
	}
}

int query(int i, int j, int s) {
	int k, p[4], res, m;
	for(k = 1; (1 << k) <= s; k++); k--;
	p[0] = dp[i][j][k];
	p[1] = dp[i][j + s - (1 << k)][k];
	p[2] = dp[i + s - (1 << k)][j][k];
	p[3] = dp[i + s - (1 << k)][j + s - (1 << k)][k];
	res = val(p[0]);
	for(m = 1; m < 4; m++) {
		if(res < val(p[m])) {
			res = val(p[m]);
		}
	}
	return res;
}

int main() {
	int test, cs, q, i, j, s;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &q);
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &a[i][j]);
		init();
		printf("Case %d:\n", cs);
		while(q--) {
			scanf("%d %d %d", &i, &j, &s);
			printf("%d\n", query(i-1, j-1, s));
		}
	}
	return 0;
}
