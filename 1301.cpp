#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;

int main() {
	int test, cs, i, k, x, y, sum, res, n;
	pii ts[100000];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = k = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			ts[k++] = pii(x, -1);
			ts[k++] = pii(y, 1);
		}
		sort(ts, ts + k);
		for(i = sum = res = 0; i < k; i++) {
			sum -= ts[i].second;
			if(sum > res) res = sum;
		}
		printf("Case %d: %d\n", cs, res);
	}
	return 0;
}