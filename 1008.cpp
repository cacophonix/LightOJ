#include <cstdio>
#include <cmath>

int main() {
	int test, cs = 1;
	long long x, y, sq, distance, n;
	scanf("%d", &test);
	while(test--) {
		scanf("%lld",&n);
		sq = sqrt(n);
		distance = n - sq * sq;
		if(!distance) x = 1, y = sq;
		else if(distance<=sq+1) x = distance, y = sq + 1;
		else x = sq + 1, y = (sq<<1) + 2 - distance;
		if(!(sq&1)) n = x, x = y, y = n;
		printf("Case %d: %lld %lld\n",cs++,x,y);
	}  
	return 0;
}  
