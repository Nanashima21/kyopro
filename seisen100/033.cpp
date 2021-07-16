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
    vector<vector<char>> v(h,vector<char> (w));
    int cntw=0;
    rep(i,h) rep(j,w) {
        cin >> v[i][j];
        if(v[i][j]=='.') cntw++;
    }
    queue<pair<int,int>> q;
    vector<int> dist(h*w,-1);
    q.push(make_pair(0,0));
    dist[0]=1;
    while(!q.empty()) {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        rep(i,4) {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||nx>=w||ny<0||ny>=h) continue;
            if(v[ny][nx]=='#') continue;
            if(dist[w*ny+nx]!=-1) continue;
            dist[w*ny+nx]=dist[w*y+x]+1;
            q.push(make_pair(ny,nx));
        }
    }
    if(dist[w*h-1]==-1) cout << -1 << endl;
    else cout << cntw-dist[w*h-1] << endl;
    return 0;
}
