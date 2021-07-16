#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<pair<ll,ll>> p(n);
    rep(i,n) {
        int c,r;
        cin >> c >> r;
        p[i]=make_pair(c,r);
    }
    vector<vector<ll>> G(n,vector<ll> ());
    rep(i,k) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    priority_queue<tupl,vector<tupl>,greater<>> pq;
    vector<vector<ll>> cost(n,vector<ll> (n+1,INF));
    cost[0][0]=0;
    pq.emplace(0,0,0);
    while(!pq.empty()) {
        //auto [d,v,r]=pq.top();
        ll d=get<0>(pq.top());
        ll v=get<1>(pq.top());
        ll r=get<2>(pq.top());
        pq.pop();
        if(cost[v][r]<d) continue;
        for(auto u:G[v]) {
            if(r>0&&cost[u][r-1]>d) {
                cost[u][r-1]=d;
                pq.emplace(d,u,r-1);
            } 
            if(cost[u][p[v].second-1]>d+p[v].first) {
                cost[u][p[v].second-1]=d+p[v].first;
                pq.emplace(d+p[v].first,u,p[v].second-1);
            }
        }
    }
    ll ans=*min_element(all(cost[n-1]));
    cout << ans << endl;
    return 0;
}
