#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int w,h;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};
vector<bool> flag;

void dfs(const vector<vector<int> > &v,int x,int y) {
    flag[w*y+x]=true;
    rep(i,8) {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0||nx>=w||ny<0||ny>=h) continue;
        if(!flag[w*ny+nx]&&v[ny][nx]==1) dfs(v,nx,ny);
    }
}

int main()
{
    while(true) {
        cin >> w >> h;
        if(w==0&h==0) break;
        vector<vector<int> > v(h,vector<int> (w));
        rep(i,h) rep(j,w) cin >> v[i][j];
        flag.assign(h*w,false);
        int cnt=0;
        rep(i,h) rep(j,w) {
            if(!flag[w*i+j]&&v[i][j]==1) {
                dfs(v,j,i);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
