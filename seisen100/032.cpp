#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main()
{
    while(true) {
        int w,h;
        cin >> w >> h;
        if(w==0&&h==0) break;
        vector<vector<int> > tate(h,vector<int> (w-1));
        vector<vector<int> > yoko(h-1,vector<int> (w));
        rep(i,2*h-1) {
            if(i%2==0) rep(j,w-1) cin >> tate[i/2][j]; 
            else rep(j,w) cin >> yoko[i/2][j];
        }
        queue<pair<int,int> > q;
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
                if(i==0&&tate[y][x]) continue;   
                else if(i==1&&yoko[y][x]) continue;
                else if(i==2&&tate[y][x-1]) continue;
                else if(i==3&&yoko[y-1][x]) continue;
                if(dist[w*ny+nx]!=-1) continue;
                dist[w*ny+nx]=dist[w*y+x]+1;
                q.push(make_pair(ny,nx));
            }
        }
        if(dist[w*h-1]==-1) dist[w*h-1]=0;
        cout << dist[w*h-1] << endl;
    }
    return 0;
}
