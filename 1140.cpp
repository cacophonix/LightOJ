#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long i64;

i64 p10[10], zero[10], jmp[10];

i64 solve(i64 num, int p) {
	if(!p) return 1;
	i64 c = num / p10[p], n = num % p10[p], ret;
	ret = c * jmp[p-1] + (c>0 ? p10[p] : n+1) + solve(n, p-1);
	return ret;
}

int main() {
	int test, cs, i;
	i64 a, b, nb, na;
	p10[0] = zero[0] = jmp[0] = 1;
	for(i = 1; i < 10; i++) {
		p10[i] = p10[i-1] * 10;
		zero[i] = p10[i] + zero[i-1];
		jmp[i] = p10[i] * (i+1);
	}
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lld %lld", &a, &b); a--;
		if(b > 0) {
			for(i = 0; i < 10 && p10[i] <= b; i++); i--;
			nb = solve(b, i) - zero[i] + 1;
		}
		else nb = 1;
		if(a > 0) {
			for(a, i = 0; i < 10 && p10[i] <= a; i++); i--;
			na = solve(a, i) - zero[i] + 1;
		}
		else if(a == 0) na = 1;
		else na = 0;
		printf("Case %d: %lld\n", cs, nb - na);
	}
	return 0;
}
