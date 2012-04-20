#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define pii pair < int , int >
#define i64 long long
#define SET(x,y) memset(x,y,sizeof x)
#define CLR(x) SET(x,0)

char g[25][25];
int ds[25][25];
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};


int main(int argc, char **argv)
{
	int T,I,i,j,x,y,tx,ty,r,n,m;
	scanf("%d", &T);;
	for(I=1;I<=T;I++) {
		scanf("%d %d", &n, &m);
		for(i=0;i<n;i++) {
			scanf("%s",g[i]);
			for(j=0;j<m;j++) if(g[i][j]=='h') {
				x=i;
				y=j;
				break;
			}
		}
		SET(ds,63);
		queue < pii > q;
		q.push(pii(x,y));
		ds[x][y]=0;
		while(!q.empty()) {
			x=q.front().first;
			y=q.front().second;
			q.pop();
			for(i=0;i<4;i++) {
				tx=x+mv[i][0];
				ty=y+mv[i][1];
				if(tx>=0 && tx<n && ty>=0 && ty<m && g[tx][ty]!='#' && g[tx][ty]!='m'  && ds[tx][ty]>(ds[x][y]+1)) {
					ds[tx][ty]=ds[x][y]+1;
					q.push(pii(tx,ty));
				}
			}
		}
		r=0;
		for(i=0;i<n;i++) for(j=0;j<m;j++) if(g[i][j]>='a' && g[i][j]<='c') r=max(r,ds[i][j]);
		printf("Case %d: %d\n",I,r);
	}
			
	return 0;
}
