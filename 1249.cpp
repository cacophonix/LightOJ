#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, string> pis;

vector< pis > V;

int main() {
	int test, cs, i, n, h, w, l;
	string name;
	cin >> test;
	for(cs = 1; cs <= test; cs++) {
		V.clear();
		cin >> n;
		for(i = 0; i < n; i++) {
			cin >> name >> h >> w >> l;
			V.push_back(pis(h*w*l, name));
		}
		sort(V.begin(), V.end());
		if(V[0].first == V[n-1].first) printf("Case %d: no thief\n", cs);
		else printf("Case %d: %s took chocolate from %s\n", cs, V[n-1].second.c_str(), V[0].second.c_str());
	}
	return 0;
}
