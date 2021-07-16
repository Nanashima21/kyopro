#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

//floyd
/*
int main()
{
    int n,k;
    cin >> n >> k;
    ll G[101][101]={{0}};
    rep(i,n) rep(j,n) G[i][j]=(i!=j)*INF;
    rep(i,k) {
        int q;
        cin >> q;
        if(q==1) {
            int c,d;
            ll e;
            cin >> c >> d >> e;
            c--; d--;
            G[c][d]=min(e,G[c][d]);
            G[d][c]=G[c][d];
            rep(i,n) rep(j,n) {
                G[i][j]=min(G[i][j],G[i][c]+G[d][j]+e); 
                G[i][j]=min(G[i][j],G[i][d]+G[c][j]+e); 
            }
        } else {
            int a,b;
            cin >> a >> b;
            a--; b--;
            if(G[a][b]>=INF/2) cout << -1 << endl;
            else cout << G[a][b] << endl;
        }
    }
    return 0;
}
*/

#define MAX_V 100001

int main()
{
    int n,k;
    cin >> n >> k;
    vector<pair<ll,ll>> G[MAX_V];
    rep(i,k) {
        int q;
        cin >> q;
        if(q==0) {
            int a,b;
            cin >> a >> b;
            priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
            ll dist[MAX_V];
            rep(j,MAX_V) dist[j]=INF;
            dist[a]=0;
            q.push(make_pair(0,a));
            while(!q.empty()) {
                ll cd=q.top().first;
                ll cv=q.top().second;
                q.pop();
                if(dist[cv]<cd) continue;
                for(auto x:G[cv]) {
                    ll nv=x.first;
                    ll nd=cd+x.second;
                    if(dist[nv]>nd) {
                        dist[nv]=nd;
                        q.push(make_pair(nd,nv));
                    }
                }
            }
            if(dist[b]==INF) cout << -1 << endl;
            else cout << dist[b] << endl;
        } else {
            ll c,d,e;
            cin >> c >> d >> e;
            G[c].push_back(make_pair(d,e));
            G[d].push_back(make_pair(c,e));
        }
    }
    return 0;
}

