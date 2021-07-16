#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int dx1[]={0,1,1,1,0,-1};
int dx2[]={-1,0,1,0,-1,-1};
int dy[]={-1,-1,0,1,1,0};

int main()
{
    int w,h;
    cin >> w >> h;
    vector<vector<bool>> v(h+2,vector<bool> (w+2,false));
    rep(i,h) rep(j,w) {
        int x;
        cin >> x;
        if(x==1) v[i+1][j+1]=true;
    }
    queue<pair<int,int>> q;
    vector<vector<bool>> flag(h+2,vector<bool> (w+2,false));    
    q.push(make_pair(0,0));
    int ans=0;
    while(!q.empty()) {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        rep(k,6) {
            int nx,ny;
            if(y%2==1) nx=x+dx1[k];
            else nx=x+dx2[k];
            ny=y+dy[k];
            if(nx<0||nx>=w+2||ny<0||ny>=h+2) continue;
            if(flag[ny][nx]) continue;
            if(v[ny][nx]) {
                ans++;
                continue;
            }
            q.push(make_pair(ny,nx));
            flag[ny][nx]=true;
        }
    }
    cout << ans << endl;
    return 0;
}