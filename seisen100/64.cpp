#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll,ll> pl;
//typedef tuple<ll,ll,ll> tupl;

#define MAX_V 100001

int main()
{
    int v,e;
    cin >> v >> e;
    vector<pl> G[MAX_V];
    rep(i,e) {
        int s,t,w;
        cin >> s >> t >> w;
        G[s].push_back({w,t});
        G[t].push_back({w,s});
    }
    priority_queue<pl,vector<pl>,greater<pl> > pq;
    pq.push({0,0});
    vector<bool> flag(MAX_V,false);
    int cnt=0;
    while(!pq.empty()) {
        ll cd=pq.top().first;
        ll cv=pq.top().second;
        pq.pop();
        if(flag[cv]) continue;
        flag[cv]=true;
        cnt+=cd;
        rep(i,G[cv].size()) pq.push(G[cv][i]);
    } 
    cout << cnt << endl;
    return 0;
}