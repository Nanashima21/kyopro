#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int f[8][8];
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

int queen(int y) {
	if (y==8) return 1;
	for (int x=0;x<8;++x) {
		if (f[y][x]) return queen(y+1);
		int flag=0;
		for (int k=0;k<8;++k) {
			int nx=x,ny=y;
			while(!flag) {
				nx+=dx[k];
				ny+=dy[k];
				if(nx<0||nx>7||ny<0||ny>7) break;
				if(f[ny][nx]) flag=1;
			}
			if(flag) break;
		}
		if (!flag) {
			f[y][x]=1;
			if(queen(y+1)) return 1;
			f[y][x]=0;
		}
	}
	return 0;
}

int main() {
	int k,r,c;
	cin >> k;
	while (k--) {
		cin >> r >> c;
		f[r][c] = 1;
	}
	queen(0);
	for (int i=0;i<8;++i) {
		for (int j=0;j<8;++j) {
			cout << (f[i][j] ? 'Q' : '.');
		}
		cout << endl;
	}
    return 0;
}
