#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > v(n,vector<int> ());
    rep(i,n) {
        int id,m;
        cin >> id >> m;
        id--;
        rep(j,m) {
            int x;
            cin >> x;
            x--;
            v[id].push_back(x); 
        }
    }
    queue<int> q;
    vector<int> dist(n,-1);
    q.push(0);
    dist[0]=0;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        int x=v[u].size();
        rep(i,x) {
            if(dist[v[u][i]]!=-1) continue;
            q.push(v[u][i]);
            dist[v[u][i]]=dist[u]+1;
        }
    }
    rep(i,n) cout << i+1 << " " << dist[i] << endl;
    return 0;
}
