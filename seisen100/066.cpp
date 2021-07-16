#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
//typedef pair<ll,ll> pl;
//typedef tuple<ll,ll,ll> tupl;

int main()
{
    while(true) {
        int n;
        cin >> n;
        if(n==0) break;
        vector<double> x(n),y(n),z(n),r(n);
        rep(i,n) cin >> x[i] >> y[i] >> z[i] >> r[i];
        double dist[101][101]={{0}};
        rep(i,n) for(int j=i+1;j<n;j++) {
            dist[i][j]=-r[i]-r[j]+sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)+pow(z[i]-z[j],2));
            if(dist[i][j]<0) dist[i][j]=0;
        }
        vector<pair<double,int> > G[101];
        rep(i,n) for(int j=i+1;j<n;j++) {
            G[i].push_back({dist[i][j],j});
            G[j].push_back({dist[i][j],i});
        }
        priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > >  pq;
        pq.push({0.0,0});
        double ans=0;
        vector<bool> flag(101,false);
        while(!pq.empty()) {
            double cd=pq.top().first;
            int cv=pq.top().second;
            pq.pop();
            if(flag[cv]) continue;
            flag[cv]=true;
            ans+=cd;
            rep(i,G[cv].size()) pq.push(G[cv][i]);
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
