#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

#define MAX_V 100001

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<pl> G[MAX_V];
    rep(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({c,b});
        G[b].push_back({c,a});
    }
    vector<ll> dist;
    priority_queue<pl,vector<pl>,greater<pl>> pq;
    pq.push({0,0});
    ll tot=0;
    vector<bool> flag(MAX_V,false);
    while(!pq.empty()) {
        ll cd=pq.top().first;
        ll cv=pq.top().second;
        pq.pop();
        if(flag[cv]) continue;
        flag[cv]=true;
        tot+=cd;
        dist.push_back(cd);
        for(auto u:G[cv]) pq.push(u);
    }
    sort(all(dist));
    rep(i,k-1) tot-=dist[dist.size()-1-i];
    cout << tot << endl;
    return 0;
}