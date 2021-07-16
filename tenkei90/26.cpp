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

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int> ());
    rep(i,n-1) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> res1,res2;
    vector<ll> dist(n,INF);
    queue<int> q;
    q.push(0);
    dist[0]=0;
    res1.push_back(dist[0]);
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        for(auto u:v[x]) {
            if(dist[u]!=INF) continue;
            dist[u]=dist[x]+1;
            if(dist[u]%2==0) res1.push_back(u);
            else res2.push_back(u);
            q.push(u);
        }
    }
    if(res1.size()>=n/2) {
        rep(i,n/2) {
            if(i) cout << " ";
            cout << res1[i]+1;
        }
    } else {
        rep(i,n/2) {
            if(i) cout << " ";
            cout << res2[i]+1;
        }
    }
    cout << endl;
    return 0;
}