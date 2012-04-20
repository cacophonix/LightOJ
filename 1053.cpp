#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int test, cs, a[3];
	char verdict[2][4] = {"no", "yes"};
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", a, a+1, a+2);
		sort(a, a + 3);
		printf("Case %d: %s\n", cs, verdict[a[2]*a[2]-a[1]*a[1] == a[0]*a[0]]);
	}
	return 0;
}
