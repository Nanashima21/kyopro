#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

int h,w;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
vector<string> s;
vector<bool> flag;

int dfs(int sx,int sy,int x,int y) {
    if(sx==x&&sy==y&&flag[w*sx+sy]) return 0;
    flag[w*x+y]=true;
    int res=-10000;
    rep(i,4) {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0||nx>=h||ny<0||ny>=w) continue;
        if(s[nx][ny]=='#') continue;
        if((sx!=nx||sy!=ny)&&flag[w*nx+ny]) continue;
        int v=dfs(sx,sy,nx,ny);
        res=max(res,v+1);
    }
    flag[w*x+y]=false;
    return res;
}

int main()
{
    cin >> h >> w;
    s.resize(h);
    rep(i,h) cin >> s[i];
    int ans=0;
    flag.assign(h*w,false);
    rep(i,h) rep(j,w) {
        if(s[i][j]=='#') continue;
        ans=max(ans,dfs(i,j,i,j));
    }
    if(ans<=3) ans=-1;
    cout << ans << endl;
    return 0;
}