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
    int n;
    cin >> n;
    vector<pl> x,y;
    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        x.push_back({a,i});
        y.push_back({b,i});
    }
    sort(all(x));
    sort(all(y));
    vector<pl> G[MAX_V];
    rep(i,n-1) {
        G[x[i].second].push_back({abs(x[i].first-x[i+1].first),x[i+1].second});
        G[x[i+1].second].push_back({abs(x[i].first-x[i+1].first),x[i].second});
        G[y[i].second].push_back({abs(y[i].first-y[i+1].first),y[i+1].second});
        G[y[i+1].second].push_back({abs(y[i].first-y[i+1].first),y[i].second});
    }
    priority_queue<pl,vector<pl>,greater<pl>> pq;
    pq.push({0,0});
    ll ans=0;
    vector<bool> flag(n,false);
    while(!pq.empty()) {
        ll cd=pq.top().first;
        ll cv=pq.top().second;
        pq.pop();
        if(flag[cv]) continue;
        flag[cv]=true;
        ans+=cd;
        for(auto u:G[cv]) pq.push(u);
    }
    cout << ans << endl;
    return 0;
}