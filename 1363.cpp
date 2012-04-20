#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAX = 1000;
const char *s[4] = {"impossible", "row", "column", "both"};

char buff[MAX+1];
int row[MAX], col[MAX], tmp[MAX];

int calc(int *a, int n, int per) {
	int i, mid, ans = 0;
	for(i = 0; i < n; i++) tmp[i] = per - a[i];
	for(i = n-2; i > 0; i--) tmp[i] = tmp[i+1] + tmp[i];
	tmp[0] = 0; sort(tmp, tmp + n);
	mid = (tmp[n>>1] + tmp[(n-1)>>1]) >> 1;
	for(i = 0; i < n; i++) ans += abs(tmp[i] - mid);
	return ans;
}

int main() {
	int test, cs, r, c, tot, flag, ans, i, j;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &r, &c);
		memset(row, 0, sizeof(int)*r);
		memset(col, 0, sizeof(int)*c);
		for(i = tot = 0; i < r; i++) {
			scanf("%s", buff);
			for(j = 0; j < c; j++) {
				if(buff[j] == '1') {
					row[i]++, col[j]++;
					tot++;
				}
			}
		}
		flag = ans = 0;
		if(tot % r == 0) flag |= 1, ans += calc(row, r, tot / r);
		if(tot % c == 0) flag |= 2, ans += calc(col, c, tot / c);
		if(flag) printf("Case %d: %s %d\n", cs, s[flag], ans);
		else printf("Case %d: %s\n", cs, s[flag]);
	}
	return 0;
}