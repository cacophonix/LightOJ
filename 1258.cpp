#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char buff[1<<20];
vector< int > lengths;

int main() {
	int test, cs, len, i, s, e, pallen, found, j, d;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%s", buff);
		len = strlen(buff);
		lengths.clear();
		pallen = 0;
		for(i = 0; i < len; ) {
			if(i > pallen && buff[i-pallen-1] == buff[i]) {
				pallen += 2;
				i++;
				continue;
			}
			lengths.push_back(pallen);
			s = lengths.size() - 2;
			e = s - pallen;
			found = 0;
			for(j = s; j > e; j--) {
				d = j - e - 1;
				if(lengths[j] == d) {
					pallen = d;
					found = 1;
					break;
				}
				lengths.push_back(min(d, lengths[j]));
			}
			if(!found) {
				pallen = 1;
				i++;
			}
		}
		lengths.push_back(pallen);
		printf("Case %d: %d\n", cs, (len<<1) - lengths.back());
	}
	return 0;
}
