#include <cstdio>

const int MAX = 1024;

int a[MAX], n, k;

bool possible(int mx) {
	int total = 0, i, j = 0;
	for(i = 0; i <= n; i++) {
		total += a[i];
		if(total > mx) {
			j++;
			total -= a[i];
			if(total <= 0) return false;
			total = a[i];
		}
	}
	return j <= k;
}

int search(int lo, int hi) {
	int mid;
	while(lo < hi) {
		mid = (lo + hi) >> 1;
		if(possible(mid)) hi = mid;
		else lo = mid + 1;
	}
	return hi;
}

int main() {
	int test, cs, i, j, mn, mx, tot;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &k);
		mx = mn = 0;
		for(i = 0; i <= n; i++) {
			scanf("%d", a + i);
			if(a[i] > mn) mn = a[i];
			mx += a[i];
		}
		mx = search(mn, mx);
		printf("Case %d: %d\n", cs, mx);
		for(i = j = tot = 0; i <= n; i++) {
			tot += a[i];
			if(tot > mx || k-j > n-i) {
				tot -= a[i];
				printf("%d\n", tot);
				j++;
				tot = a[i];
			}
		}
		printf("%d\n", tot);
	}
	return 0;
}