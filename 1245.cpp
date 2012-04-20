#include <cstdio>

typedef long long i64;

int main() {
	int n, test, cs, temp, last_deno, end_p, start_p, i;
	i64 sum;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d",&n);
		if(n == 1) printf("Case %d: 1\n", cs);
		else {
			sum = n;
			start_p = n;
			last_deno = 1;
			for(i=2;;i++) {
				temp = n/i;
				end_p = temp;
				sum += (start_p - end_p)*last_deno;
				if(end_p < i) break;
				sum += temp;
				last_deno = i;
				start_p = end_p;
				if(end_p==i) break;
			}
			printf("Case %d: %lld\n",cs, sum);
		}
	}
	return 0;
}

