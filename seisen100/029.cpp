#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main()
{
    int h,w;
    cin >> h >> w;
    int sy,sx,gy,gx;
    cin >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--;
    vector<vector<char>> v(h,vector<char> (w));
    rep(i,h) rep(j,w) cin >> v[i][j];
    queue<pair<int,int>> q;
    vector<int> dist(h*w,-1);
    q.push(make_pair(sy,sx));
    dist[w*sy+sx]=0;
    int ans=h*w;
    while(!q.empty()) {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        rep(i,4) {
            int nx=x+dx[i],ny=y+dy[i];
            if(v[ny][nx]=='#') continue;
            if(nx<0||nx>=w||ny<0||ny>=h) continue;
            if(dist[w*ny+nx]!=-1) continue;
            q.push(make_pair(ny,nx));
            dist[w*ny+nx]=dist[w*y+x]+1;
            if(nx==gx&&ny==gy) ans=min(dist[w*ny+nx],ans);
        }
    }
    cout << ans << endl;
    return 0;
}
