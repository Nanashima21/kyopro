#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int v,e;
    cin >> v >> e;
    ll G[101][101]={{0}};
    rep(i,v) rep(j,v) G[i][j]=(i!=j)*INF;
    rep(i,e) {
        int s,t,d;
        cin >> s >> t >> d;
        G[s][t]=d;
    }
    //floyd
    rep(k,v) rep(i,v) rep(j,v) G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
    rep(i,v) if(G[i][i]<0) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    rep(i,v) {
        rep(j,v) {
            if(j) cout << " ";
            if(G[i][j]>=INF/2) cout << "INF";
            else cout << G[i][j];
        }
        cout << endl;
    }
    return 0;
}