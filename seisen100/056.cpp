#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

#define MAX_V 100001

int main()
{
    int v,e,r;
    cin >> v >> e >> r;
    vector<pair<ll,ll> > G[MAX_V];
    rep(i,e) {
        int s,t;
        ll w;
        cin >> s >> t >> w;
        G[s].push_back(make_pair(t,w));
    } 
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >, greater<pair<ll,ll> > > q;
    ll dist[MAX_V];
    rep(i,MAX_V) dist[i]=INF;
    dist[r]=0;
    q.push(make_pair(0,r));
    while(!q.empty()) {
        ll cd=q.top().first;
        ll cv=q.top().second;
        q.pop();
        if(dist[cv]<cd) continue;
        rep(i,G[cv].size()) {
            ll nv=G[cv][i].first;
            ll nd=cd+G[cv][i].second;
            if(dist[nv]>nd) {
                dist[nv]=nd;
                q.push(make_pair(nd,nv));
            }
        }
    }
    rep(i,v) {
        if(dist[i]==INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}
