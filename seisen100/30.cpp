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
    int h,w,n;
    cin >> h >> w >> n;
    vector<vector<char>> v(h,vector<char> (w));
    int sx,sy;
    rep(i,h) rep(j,w) {
        cin >> v[i][j];
        if(v[i][j]=='S') {
            sx=j;
            sy=i;
        }
    }
    queue<pair<int,int>> q;
    vector<int> dist(h*w,-1);
    q.push(make_pair(sy,sx));
    dist[w*sy+sx]=0;
    int cnt=1,ans=0;
    while(!q.empty()) {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        if(dist[w*y+x]==-1) continue;
        bool flag=false,check=false;
        rep(i,4) {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||nx>=w||ny<0||ny>=h) continue;
            if(v[ny][nx]=='X') continue;
            if(dist[w*ny+nx]!=-1) continue;
            int d=dist[w*y+x]+1;
            if(v[ny][nx]-'0'==cnt) {
                cnt++;
                q=queue<pair<int,int>> ();
                dist.assign(h*w,-1);
                flag=true;
                if(cnt==n+1) check=true;
            }
            dist[w*ny+nx]=d;
            q.push(make_pair(ny,nx));
            ans=d;
            if(flag) break;
        }
        if(check) break;
    }
    cout << ans << endl;
    return 0;
}