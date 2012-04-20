#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 1009, INF = 0x3f3f3f3f;
char line[MAX][MAX];
int d[MAX][MAX], R, C;
int dr[] = {0, 0, 1,-1};
int dc[] = {1,-1, 0, 0};

bool valid(int r, int c) {
	return (r>=0 && r<R && c>=0 && c<C);
}

bool escape(int r, int c) {
	return (r==0 || c==0 || r==R-1 || c==C-1);
}

void fire() {
	queue< int > Q;
	int ur, uc, vr, vc, i, j;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(line[i][j]=='F') {
				d[i][j] = 0;
				Q.push(i); Q.push(j);
			}
		}
	}
	while(!Q.empty()) {
		ur = Q.front(); Q.pop();
		uc = Q.front(); Q.pop();
		for(i = 0; i < 4; i++) {
			vr = ur + dr[i];
			vc = uc + dc[i];
			if(valid(vr, vc) && d[vr][vc] > d[ur][uc] + 1) {
				d[vr][vc] = d[ur][uc] + 1;
				Q.push(vr); Q.push(vc);
			}
		}
	}
}

int joe(int sr, int sc) {
	queue< int > Q;
	int uc, ur, vc, vr, i;
	if(escape(sr, sc)) return 0;
	d[sr][sc] = 0;
	Q.push(sr); Q.push(sc);
	while(!Q.empty()) {
		ur = Q.front(); Q.pop();
		uc = Q.front(); Q.pop();
		for(i = 0; i < 4; i++) {
			vr = ur + dr[i];
			vc = uc + dc[i];
			if(valid(vr, vc) && d[vr][vc] > d[ur][uc] + 1) {
				d[vr][vc] = d[ur][uc] + 1;
				if(escape(vr, vc)) return d[vr][vc];
				Q.push(vr); Q.push(vc);
			}
		}
	}
	return -1;
}

int main() {
	int t, i, j, jr, jc, x, cs = 1;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &R, &C);
		for(i = 0; i < R; i++) {
			scanf("%s", line[i]);
			for(j = 0; j < C; j++) {
				if(line[i][j]=='J') jr = i, jc = j;
				else if(line[i][j]=='#') d[i][j] = -1;
				else d[i][j] = INF;
			}
		}
		fire();
		x = joe(jr, jc);
		if(x < 0) printf("Case %d: IMPOSSIBLE\n", cs++);
		else printf("Case %d: %d\n", cs++, x + 1);
	}
	return 0;
}
