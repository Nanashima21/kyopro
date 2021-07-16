#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int w,h;
int ans=0;
vector<bool> flag;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void dfs(vector<vector<int>> &v,int x,int y,int cnt) {
    flag[w*y+x]=true;
    bool check=true;
    rep(i,4) {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0||nx>=w||ny<0||ny>=h) continue;
        if(!flag[w*ny+nx]&&v[ny][nx]==1) {
            dfs(v,nx,ny,cnt+1);
            check=false;
        }
    }
    flag[w*y+x]=false;
    if(check) ans=max(ans,cnt);
}

int main()
{
    cin >> w >> h;
    vector<vector<int>> v(h,vector<int> (w));
    rep(i,h) rep(j,w) cin >> v[i][j];
    rep(i,h) {
        rep(j,w) {
            flag.assign(h*w,false);
            int cnt=1;
            if(v[i][j]==1) dfs(v,j,i,cnt);
        }
    }
    cout << ans << endl;
    return 0;
}