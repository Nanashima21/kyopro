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

int nd,ma=0;
vector<bool> flag;

void dfs(const vector<vector<int>> &v,int i,int cnt) {
    flag[i]=true;
    for(auto u:v[i]) {
        if(flag[u]) continue;
        dfs(v,u,cnt+1);
    }
    if(cnt>ma) {
        ma=cnt;
        nd=i;
    }
}

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
    rep(i,n) if(v[i].size()==1) nd=i;
    int ans=0;
    while(true) {
        int cnt=0;
        flag.assign(n,false);
        dfs(v,nd,cnt);
        if(ma==ans) break;
        ans=max(ans,ma);
    }
    cout << ans+1 << endl;
    return 0;
}