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
    vector<vector<int>> v(n,vector<int> (n));
    vector<vector<int>> flag(n,vector<int> (n,-1));
    rep(i,n) rep(j,n) cin >> v[i][j];
    int m;
    cin >> m;
    rep(i,m) {
        int x,y;
        cin >> x >> y;
        x--; y--;
        flag[x][y]=1;
        flag[y][x]=1;
    }
    vector<int> x(n);
    rep(i,n) x[i]=i;
    ll ans=INF;
    do {
        bool check=true;
        ll sum=0;
        sum+=v[x[0]][0];
        for(int i=1;i<n;i++) {
            sum+=v[x[i]][i];
            if(flag[x[i-1]][x[i]]==1) check=false;
        } 
        if(check) ans=min(ans,sum);
    } while(next_permutation(all(x)));
    if(ans==INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}