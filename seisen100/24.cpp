#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

vector<bool> flag;
vector<int> first_order;
vector<int> last_order;

void dfs(const Graph &G,int v,int& ptr) {
    first_order[v]=ptr++;
    flag[v]=true;
    for(auto next_v:G[v]) {
        if(flag[next_v]) continue;
        dfs(G,next_v,ptr);
    }
    last_order[v]=ptr++;
}

int main()
{
    int n;
    cin >> n;
    Graph G(n,vector<int> ());
    rep(i,n) {
        int id,m;
        cin >> id >> m;
        id--;
        rep(i,m) {
            int a;
            cin >> a;
            a--;
            G[id].push_back(a);
        }
    }
    flag.assign(n,false);
    first_order.resize(n);
    last_order.resize(n);
    int ptr=1;
    rep(i,n) if(!flag[i]) dfs(G,i,ptr);
    rep(i,n) cout << i+1 << " " << first_order[i] << " " << last_order[i] << endl;
    return 0;
}