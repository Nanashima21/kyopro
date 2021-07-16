#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll,ll> pl;

int main()
{
    ll n,m,k,s;
    cin >> n >> m >> k >> s;
    ll p,q;
    cin >> p >> q;
    vector<ll> v(n,-1);
    queue<ll> que;
    rep(i,k) {
        ll d;
        cin >> d;
        d--;
        v[d]=0;
        que.push(d);
    }
    vector<vector<ll>> G(n);
    rep(i,m) {
        ll a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    while(!que.empty()) {
        ll u=que.front();
        que.pop();
        for(auto x:G[u]) {
            if(v[x]!=-1) continue;
            v[x]=v[u]+1;
            que.push(x);
        }
    }
    priority_queue<pl,vector<pl>,greater<pl>> pq;
    vector<ll> cost(n,INF);
    cost[0]=0;
    pq.emplace(0,0);
    while(!pq.empty()) {
        ll cc=pq.top().first;
        ll cv=pq.top().second;
        pq.pop();
        if(cost[cv]<cc) continue;
        for(auto x:G[cv]) {
            ll nc;
            if(v[x]==0) nc=INF;
            else if(v[x]<=s) nc=q;
            else nc=p;
            if(cost[x]>cc+nc) {
                cost[x]=cc+nc;
                pq.emplace(cc+nc,x);
            }
        }
    }
    if(v[n-1]<=s) cout << cost[n-1]-q << endl;
    else cout << cost[n-1]-p << endl;
    return 0;
}
