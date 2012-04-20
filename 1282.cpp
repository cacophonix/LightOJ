#include <cstdio>  
#include <cmath>  

int main() {
	int test, cs, n, k, head, tail;
	long double c, dn;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d",&n, &k);
		dn = n; n = n % 1000; tail = 1;
		c = k * log10(dn);
		c = c - floor(c);
		head = (int)pow((long double)10.0, 2 + c);
		while(k) {
			if(k & 1) tail =(tail * n) % 1000;
			k >>= 1, n =(n * n) % 1000;
		}
		printf("Case %d: %d %03d\n", cs, head, tail);
	}
	return 0;
}
