#include <cstdio>
#include <algorithm>
using namespace std;

int yeyenum[512][512], bloggium[512][512], maximum[512][512];

int main() {
	int test, cs, i, j, sum, pre, R, C;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &R, &C);
		for(i = 0; i < R; i++)
			for(j = 0; j < C; j++)
				scanf("%d", &yeyenum[i][j]);
		for(i = 0; i < R; i++)
			for(j = 0; j < C; j++)
				scanf("%d", &bloggium[i][j]);
		for(i = 0; i < R; i++) {
			for(sum = j = 0; j < C; j++) {
				sum += bloggium[i][j];
			}
			pre = i > 0? maximum[i-1][0] : 0;
			maximum[i][0] = pre + sum;
			for(j = 1; j <= C; j++) {
				sum += yeyenum[i][j-1] - bloggium[i][j-1];
				pre = i > 0? max(pre, maximum[i-1][j]) : 0;
				maximum[i][j] = pre + sum;
			}
		}
		for(j = 1, sum = maximum[i-1][0]; j <= C; j++) {
			sum = max(sum, maximum[i-1][j]);
		}
		printf("Case %d: %d\n", cs, sum);
	}
	return 0;
}
