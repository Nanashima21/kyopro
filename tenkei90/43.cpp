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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct state {
    int x,y,z;
};

int main()
{
    int h,w;
    cin >> h >> w;
    int rs,cs,rt,ct;
    cin >> rs >> cs >> rt >> ct;
    rs--; cs--; rt--; ct--;
    ll dist[1010][1010][4];
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h) rep(j,w) rep(k,4) dist[i][j][k]=INF;
    deque<state> dq;
    rep(i,4) {
        dist[rs][cs][i]=0;
        dq.push_back({rs,cs,i});
    }
    while(!dq.empty()) {
        state u=dq.front();
        dq.pop_front();
        rep(i,4) {
            int nx=u.x+dx[i],ny=u.y+dy[i];
            int cost=dist[u.x][u.y][u.z];
            if(u.z!=i) cost++; 
            if(nx<0||nx>=h||ny<0||ny>=w) continue;
            if(s[nx][ny]=='#') continue;
            if(dist[nx][ny][i]<=cost) continue;
            dist[nx][ny][i]=cost;
            if(u.z!=i) dq.push_back({nx,ny,i});
            else dq.push_front({nx,ny,i});
        }
    }
    ll ans=INF;
    rep(i,4) ans=min(ans,dist[rt][ct][i]);
    cout << ans << endl;
    return 0;
}